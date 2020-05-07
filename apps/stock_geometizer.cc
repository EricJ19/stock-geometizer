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

namespace stockgeoapp {

using cinder::app::KeyEvent;

StockGeo::StockGeo() {
}

void StockGeo::setup() {
  ImGui::initialize();

  // All geometry are vertically centered.
  mid_window_height = getWindowHeight() / kHalf;

  // This represents the scaling factor to get one third of the window
  // either vertically or horizontally.
  const double kOneThirdScale = 0.25;
  // Window center is the default value if geo_numb does not match.
  third_of_window_width = kOneThirdScale * getWindowWidth();
}

void StockGeo::update() {
  // Updates finance data based on last API responses to each ImGui::InputText.
  SetGeoData(first_fin_data, first_geo);
  SetGeoData(second_fin_data, second_geo);
  SetGeoData(third_fin_data, third_geo);
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
  // Arbitrary x and y width, but large enough to see InputText labels.
  const ImVec2 kStockWindowSize = ImVec2(200,200);
  ImGui::SetNextWindowSize(kStockWindowSize);

  ImGui::Begin("Geometizer");

  ImGui::Text("Input a Stock");

  // Allows user to input up to three different stocks.

  ImGui::InputText(
      "Stock1",
      first_input_chars,
      IM_ARRAYSIZE(first_input_chars));

  if (ImGui::Button("Ok1")) {
    // Set user input into string to be used for API calls
    first_input_str = first_input_chars;
    ReceiveAPICallData(first_input_str, kFirstGeoNumb);
  }

  ImGui::InputText(
      "Stock2",
      second_input_chars,
      IM_ARRAYSIZE(second_input_chars));

  if (ImGui::Button("Ok2")) {
    second_input_str = second_input_chars;
    ReceiveAPICallData(second_input_str, kSecondGeoNumb);
  }

  ImGui::InputText(
      "Stock3", third_input_chars,
      IM_ARRAYSIZE(third_input_chars));

  if (ImGui::Button("Ok3")) {
    third_input_str = third_input_chars;
    ReceiveAPICallData(third_input_str, kThirdGeoNumb);
  }

  ImGui::End();
}

void StockGeo::DrawGeo() {
  // Note: Outer shape is drawn first so that the inner
  // shape drawn on top outer shape or else cover by the outer shape.

  DrawOuterShape(first_geo, kFirstGeoNumb);
  DrawOuterShape(second_geo, kSecondGeoNumb);
  DrawOuterShape(third_geo, kThirdGeoNumb);

  DrawInnerShape(first_geo, kFirstGeoNumb);
  DrawInnerShape(second_geo, kSecondGeoNumb);
  DrawInnerShape(third_geo, kThirdGeoNumb);
}

void StockGeo::ReceiveAPICallData(const std::string& user_input,
                                  int geo_numb) {
  // API calls for financial data.
  // Specific stock being called is custom, based on user inputs.
  cpr::Response price_quote_response = cpr::Get(cpr::Url{
    kPriceQuoteBeginURL + user_input + kPriceQuoteEndURL});

  cpr::Response price_metrics_response = cpr::Get(cpr::Url{
    kMetricsBeginURL + user_input + kPriceMetricEndURL});

  cpr::Response growth_metrics_response = cpr::Get(cpr::Url{
    kMetricsBeginURL + user_input + kGrowthMetricEndURL});

  cpr::Response recommendations_response = cpr::Get(cpr::Url{
    kRecommendationBeginURL + user_input + kRecommendationsEndURL});

  try {
    // Store API response in JSON format.
    nlohmann::json parse_price_quote =
        nlohmann::json::parse(price_quote_response.text);

    nlohmann::json parse_price_metrics =
        nlohmann::json::parse(price_metrics_response.text);

    nlohmann::json parse_growth_metrics =
        nlohmann::json::parse(growth_metrics_response.text);

    nlohmann::json parse_recommendations =
        nlohmann::json::parse(recommendations_response.text);

    // Determine which finance data set to modify based on which
    // ImGui::Button was clicked.
    finance::FinanceData& finance_set_to_modify = FindFinSetToAnalyze(geo_numb);

    // Modify finance data set based on API responses and
    // which ImGui::InputText user changed.
    SetFinanceData(finance_set_to_modify, parse_price_quote,
                   parse_price_metrics, parse_growth_metrics,
                   parse_recommendations);
  } catch (std::exception& e) {
    // Simply don't respond if parsing fails.
    return;
  }
}

finance::FinanceData& StockGeo::FindFinSetToAnalyze(const int &geo_numb) {
  if (geo_numb == kFirstGeoNumb) {
    return first_fin_data;
  } else if (geo_numb == kSecondGeoNumb) {
    return second_fin_data;
  } else if (geo_numb == kThirdGeoNumb) {
    return third_fin_data;
  } else {
    // geo_numb must be between 1 to kMaxNumbOfGeos.
    throw std::exception();
  }
}

void StockGeo::SetFinanceData(finance::FinanceData& fin_data,
                    const nlohmann::json& parse_price_quote,
                    const nlohmann::json& parse_price_metrics,
                    const nlohmann::json& parse_growth_metrics,
                    const nlohmann::json& parse_recommendations) {
  // Parse price quote response. This is a 1-D JSON array and so only
  // the key is needed (without parsing into arrays) to get value.
  const std::string kOpeningPriceKey = "o";
  fin_data.SetPriceQuote(
      parse_price_quote.value(
          kOpeningPriceKey, 0));

  // Parse 26 Week Price Return Daily. Parses into 2-D array.
  for (auto& elem : parse_price_metrics.items()) {
    if (elem.key() == "metric") {
      nlohmann::json price_metrics = elem.value();
      fin_data.Set26WkPriceReturn(
          price_metrics.value(
              "26WeekPriceReturnDaily",0));
      break;
    }
  }

  // Parse 3 Year Growth. Parses into 2-D array.
  for (auto& elem : parse_growth_metrics.items()) {
    if (elem.key() == "metric") {
      nlohmann::json growth_metrics = elem.value();
      fin_data.Set3YrRevGrowthRate(
          growth_metrics.value(
              "epsGrowth3Y",0));
      break;
    }
  }

  // Parses 2-D array for number of recommendations for selling, holding,
  // and buying the stock.
  // This key represents recommendations for the same day API was called.
  const std::string kDailyRecKey = "0";
  for (auto& elem : parse_recommendations.items()) {
    if (elem.key() == kDailyRecKey) {
      nlohmann::json recommendations = elem.value();
      fin_data.SetBuyRec(
          recommendations.value(
              "buy",0));

      fin_data.SetSellRec(
          recommendations.value(
              "sell", 0));

      fin_data.SetHoldRec(
          recommendations.value(
              "hold", 0));

      fin_data.SetStrongBuyRec(
          recommendations.value(
              "strongBuy", 0));

      fin_data.SetStrongSellRec(
          recommendations.value(
              "strongSell",0));
      break;
    }
  }
}

void StockGeo::SetGeoData(finance::FinanceData& fin_data,
                              geometry::Geometry& geo_data ) {
  geo_data.SetInnerColors(fin_data);
  geo_data.SetOuterColors(fin_data);

  geo_data.SetInnerEdges(fin_data);
  geo_data.SetOuterEdges(fin_data);
};

void StockGeo::DrawOuterShape(geometry::Geometry& geo_data, int geo_numb) {
  // Draw outer color.
  cinder::gl::color(geo_data.GetOuterRedColor(),
                    geo_data.GetOuterGreenColor(),
                    geo_data.GetOuterBlueColor());
  int numb_outer_segments = geo_data.GetOuterEdgeNumber();

  // Draw outer geometry.
  cinder::vec2 center_outer_shape;
  // Ensure geo_numb is appropriate to properly display geometry.
  if (geo_numb <= 0 || geo_numb > kMaxNumbOfGeos) {
    return;
  } else {
    center_outer_shape
        = {third_of_window_width * geo_numb, mid_window_height};
  }

  cinder::gl::drawSolidCircle(center_outer_shape,
                              kOuterRadius,
                              numb_outer_segments);
}

void StockGeo::DrawInnerShape(geometry::Geometry& geo_data, int geo_numb) {
  // Draw inner color.
  cinder::gl::color(geo_data.GetInnerRedColor(),
                    geo_data.GetInnerGreenColor(),
                    geo_data.GetInnerBlueColor());

  int numb_inner_segments = geo_data.GetInnerEdgeNumber();

  // Draw inner geometry.
  cinder::vec2 center_inner_shape;
  // Ensure geo_numb is appropriate to properly display geometry.
  if (geo_numb <= 0 || geo_numb > kMaxNumbOfGeos) {
    return;
  } else {
    center_inner_shape
      = {third_of_window_width * geo_numb, mid_window_height};
  }

  cinder::gl::drawSolidCircle(center_inner_shape,
                              kInnerRadius,
                              numb_inner_segments);
}

}  // namespace stockgeoapp
