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
    int numb_segments = 100;
    // Set user input into string to be used for API calls
    first_input_str = first_input_chars;
    ReceiveAPICallData(first_input_str);
  }

  ImGui::InputText("Stock2", second_input_chars, IM_ARRAYSIZE(second_input_chars));
  if (ImGui::Button("Ok")) {
    second_input_str = second_input_chars;
    ReceiveAPICallData(second_input_str);
  }

  ImGui::InputText("Stock3", third_input_chars, IM_ARRAYSIZE(third_input_chars));
  if (ImGui::Button("Ok")) {
    third_input_str = second_input_chars;
    ReceiveAPICallData(third_input_str);
  }

  ImGui::End();
}

void StockGeo::DrawGeo() {

}

void StockGeo::ReceiveAPICallData(const std::string& user_input) {
  // Custom API calls based on user inputs.
  cpr::Response metrics_response;
  try {
    metrics_response
      = cpr::Get(cpr::Url{kMetricsBeginURL + user_input
                          + "&freq=annual&token=" + kAPIKey});
  } catch (std::exception& e) {
    //TODO:Handle more gracefully.
    return;
  }

  nlohmann::json json_response = metrics_response.text;
}

}  // namespace myapp
