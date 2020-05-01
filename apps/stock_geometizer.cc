// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "stock_geometizer.h"

#include <cinder/app/App.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>

#include "../blocks/Cinder-ImGui/include/CinderImGui.h"
#include "cpr/api.h"
#include "cpr/auth.h"
#include "cpr/cprtypes.h"
#include "cpr/parameters.h"
#include "nlohmann/json.hpp"

namespace myapp {

using cinder::app::KeyEvent;

StockGeo::StockGeo() {
}

void StockGeo::setup() {
  ImGui::initialize();
}

void StockGeo::update() {

}

void StockGeo::draw() {
  // Clears the background to black
  cinder::gl::clear();

  CreateStockWindow();
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
    third_input_str = second_input_chars;
    ReceiveAPICallData(third_input_str, kThirdGeoNumb);
  }

  ImGui::End();
}

void StockGeo::DrawGeo() {

}

void StockGeo::ReceiveAPICallData(const std::string& user_input,
                                  int geometry_number) {
  // Custom API calls based on user inputs.
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
  nlohmann::json json_price_quote_response = price_quote_response.text;
  nlohmann::json json_price_metrics_response = price_metrics_response.text;
  nlohmann::json json_growth_metrics_response = growth_metrics_response.text;
  nlohmann::json json_recommendations_response = recommendations_response.text;

  // Populate the respective finance data set.
  switch(geometry_number) {
    case 1:
      SetFinanceData(first_fin_data, geometry_number);
      break;
    case 2:
      SetFinanceData(first_fin_data, geometry_number);
      break;
    case 3:
      SetFinanceData(first_fin_data, geometry_number);
      break;
  }
}

void StockGeo::SetFinanceData(finance::FinanceData& fin_data,
                              int geometry_number) {
  
};

}  // namespace myapp
