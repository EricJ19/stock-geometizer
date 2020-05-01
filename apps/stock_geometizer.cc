// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "stock_geometizer.h"

#include <cinder/app/App.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>

#include "../blocks/Cinder-ImGui/include/CinderImGui.h"
#include "cpr/api.h"
#include "cpr/auth.h"
#include "cpr/cprtypes.h"
#include "nlohmann/json.hpp"

namespace myapp {

using cinder::app::KeyEvent;

StockGeo::StockGeo() {
}

void StockGeo::setup() {
  ImGui::initialize();
}

void StockGeo::update() {
  // Updates finance data based on last API responses to each ImGui::InputText.
  SetGeoData(first_fin_data, first_geo);
  //SetGeoData(second_fin_data, second_geo);
  //SetGeoData(third_fin_data, third_geo);
}

void StockGeo::draw() {
  // Clears the background to black.
  cinder::gl::clear();

  // Create ImGui::Window for user inputs.
  CreateStockWindow();

  // Draws geometrical shapes from stock input.
  DrawGeo();
}

void StockGeo::keyDown(KeyEvent event) { }

void StockGeo::CreateStockWindow() {
  ImGui::Begin("Geometizer");

  ImGui::Text("Input a Stock");

  // Allows user to input up to three different stocks.
  ImGui::InputText("Stock1", first_input_chars, IM_ARRAYSIZE(first_input_chars));
  if (ImGui::Button("Ok")) {
    // Set user input into string to be used for API calls
    first_input_str = first_input_chars;
    ReceiveAPICallData(first_input_str, kFirstGeoNumb);
  }

  ImGui::InputText("Stock2", second_input_chars, IM_ARRAYSIZE(second_input_chars));
  if (ImGui::Button("Ok")) {
    second_input_str = second_input_chars;
    ReceiveAPICallData(second_input_str, kSecondGeoNumb);
  }

  ImGui::InputText("Stock3", third_input_chars, IM_ARRAYSIZE(third_input_chars));
  if (ImGui::Button("Ok")) {
    third_input_str = third_input_chars;
    ReceiveAPICallData(third_input_str, kThirdGeoNumb);
  }

  ImGui::End();
}

void StockGeo::DrawGeo() {
  //TODO: Finish Creating Geometry for all 3 Data Sets.
  //TODO: Make Color Transparent.

  // Note: Outer shape is drawn first so that the inner
  // shape drawn on top outer shape or else cover by the outer shape.

  DrawOuterShape(first_geo, kFirstGeoNumb);
  //DrawOuterShape(second_geo, kSecondGeoNumb);
  //DrawOuterShape(third_geo, kThirdGeoNumb);

  DrawInnerShape(first_geo, kFirstGeoNumb);
  //DrawInnerShape(second_geo, kSecondGeoNumb);
  //DrawInnerShape(third_geo, kThirdGeoNumb);
}

void StockGeo::ReceiveAPICallData(const std::string& user_input,
                                  int geo_numb) {
  // API calls for financial data.
  // Specific stock being called is custom, based on user inputs.
  cpr::Response price_quote_response;
  cpr::Response price_metrics_response;
  cpr::Response growth_metrics_response;
  cpr::Response recommendations_response;

  try {
    price_quote_response = cpr::Get(cpr::Url{
        kPriceQuoteBeginURL + user_input + kPriceQuoteEndURL});

    price_metrics_response = cpr::Get(cpr::Url{
        kMetricsBeginURL + user_input + kPriceMetricEndURL});

    growth_metrics_response = cpr::Get(cpr::Url{
        kMetricsBeginURL + user_input + kGrowthMetricEndURL});

    recommendations_response = cpr::Get(cpr::Url{
        kRecommendationBeginURL + user_input + kRecommendationsEndURL});
  } catch (std::exception& e) {
    //TODO:Handle more gracefully.
    return;
  }

  // Store API response in JSON format.
  nlohmann::json parse_price_quote
    = nlohmann::json::parse(price_quote_response.text);

  nlohmann::json parse_price_metrics
    = nlohmann::json::parse(price_metrics_response.text);

  nlohmann::json parse_growth_metrics
    = nlohmann::json::parse(growth_metrics_response.text);

  nlohmann::json parse_recommendations
    = nlohmann::json::parse(recommendations_response.text);

  // Determine which finance data set to modify based on which
  // ImGui::Button was clicked.
  finance::FinanceData& finance_set_to_modify = FindFinSetToAnalyze(geo_numb);

  // Modify finance data set based on API responses and
  // which ImGui::InputText user changed.
  SetFinanceData(finance_set_to_modify,
                 parse_price_quote,
                 parse_price_metrics,
                 parse_growth_metrics,
                 parse_recommendations);
}

finance::FinanceData& StockGeo::FindFinSetToAnalyze(const int &geo_numb) {
  if (geo_numb == kFirstGeoNumb) {
    return first_fin_data;
  } else if (geo_numb == kSecondGeoNumb) {
    return second_fin_data;
  } else if (geo_numb == kThirdGeoNumb) {
    return third_fin_data;
  } else {
    throw std::string("Invalid Geometry Number");
  }
}

void StockGeo::SetFinanceData(finance::FinanceData& fin_data,
                    const nlohmann::json& parse_price_quote,
                    const nlohmann::json& parse_price_metrics,
                    const nlohmann::json& parse_growth_metrics,
                    const nlohmann::json& parse_recommendations) {
  fin_data.SetPriceQuote(parse_price_quote.value("o", 0));

  for (auto& elem : parse_price_metrics.items()) {
    if (elem.key() == "metric") {
      nlohmann::json price_metrics = elem.value();
      fin_data.Set26WkPriceReturn( price_metrics.value("26WeekPriceReturnDaily",0));
      break;
    }
  }

  for (auto& elem : parse_growth_metrics.items()) {
    if (elem.key() == "metric") {
      nlohmann::json growth_metrics = elem.value();
      fin_data.Set3YrRevGrowthRate(growth_metrics.value("epsGrowth3Y",0));
      break;
    }
  }

  // This key represents expert recommendations for the day API was called.
  const std::string kDailyRecKey = "0";
  for (auto& elem : parse_recommendations.items()) {
    if (elem.key() == kDailyRecKey) {
      nlohmann::json recommendations = elem.value();
      fin_data.SetBuyRec(recommendations.value("buy", 0));
      fin_data.SetSellRec(recommendations.value("sell", 0));
      fin_data.SetHoldRec(recommendations.value("hold", 0));
      fin_data.SetStrongBuyRec(recommendations.value("strongBuy", 0));
      fin_data.SetStrongSellRec(recommendations.value("strongSell", 0));
      break;
    }
  }
}

void StockGeo::SetGeoData(finance::FinanceData& fin_data,
                              geometry::Geometry& geo_data ) {
  geo_data.SetInnerColors(fin_data.GetBuyRec(),
                           fin_data.GetSellRec(),
                           fin_data.GetHoldRec(),
                           fin_data.GetStrongBuyRec(),
                           fin_data.GetStrongSellRec());

  geo_data.SetOuterColors(fin_data.GetPriceQuote(),
                           fin_data.Get26WkPriceReturn(),
                           fin_data.Get3YrRevGrowthRate());

  geo_data.SetInnerEdges(fin_data.GetBuyRec(),
                          fin_data.GetSellRec(),
                          fin_data.GetStrongBuyRec(),
                          fin_data.GetStrongSellRec());

  geo_data.SetOuterEdges(fin_data.GetPriceQuote(),
                          fin_data.Get26WkPriceReturn(),
                          fin_data.Get3YrRevGrowthRate());
};

//TODO: Utilize the geo_numb, enforce DRY.

void StockGeo::DrawInnerShape(geometry::Geometry& geo_data, int geo_numb) {
  cinder::gl::color(geo_data.GetInnerRedColor(),
                    geo_data.GetInnerBlueColor(),
                    geo_data.GetInnerGreenColor());

  int numb_inner_segments = geo_data.GetInnerEdgeNumber();

  // All Geometry are vertically centered.
  const double kMidWindowHeight = getWindowHeight() / kHalf;
  // Window center is the default value if geo_numb does not match.
  const double kWindowSegmentWidth = getWindowWidth() / kWindowSegmentNumb;

  cinder::vec2 center_inner_shape;
  // Ensure geo_numb is appropriate to properly display geometry.
  if (geo_numb <= 0 && geo_numb <= kMaxNumbOfGeos) {
    return;
  } else {
    center_inner_shape = {kWindowSegmentWidth * geo_numb, kMidWindowHeight};
  }

  cinder::gl::drawSolidCircle(center_inner_shape, kInnerRadius, numb_inner_segments);
}

void StockGeo::DrawOuterShape(geometry::Geometry& geo_data, int geo_numb) {
  cinder::gl::color(geo_data.GetOuterRedColor(),
                    geo_data.GetOuterBlueColor(),
                    geo_data.GetOuterGreenColor());
  int numb_outer_segments = geo_data.GetOuterEdgeNumber();

  // All Geometry are vertically centered.
  const double kMidWindowHeight = getWindowHeight() / kHalf;
  // Window center is the default value if geo_numb does not match.
  const double kWindowSegmentWidth = getWindowWidth() / kWindowSegmentNumb;

  cinder::vec2 center_outer_shape;
  // Ensure geo_numb is appropriate to properly display geometry.
  if (geo_numb <= 0 && geo_numb <= kMaxNumbOfGeos) {
    return;
  } else {
    center_outer_shape = {kWindowSegmentWidth * geo_numb, kMidWindowHeight};
  }

  cinder::gl::drawSolidCircle(center_outer_shape, kOuterRadius, numb_outer_segments);
}

}  // namespace myapp
