// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "stock_geometizer.h"

#include <cinder/app/App.h>
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
  cpr::Response response = cpr::Get(cpr::Url{"https://finnhub.io/api/v1/stock/eps-estimate?symbol=AMZN&freq=annual&token=bqhl2s7rh5rdcs9r2ovg"});
  nlohmann::json json_response = response.text;
}

void StockGeo::draw() {
  // Clears the background to black
  cinder::gl::clear();

  char first_stock_input[4];
  char second_stock_input[4];
  char third_stock_input[4];

  ImGui::Begin("Geometizer");
  cinder::gl::clear( 0);
  ImGui::Text("Input a Stock");

  ImGui::InputText("Stock1", first_stock_input, sizeof(first_stock_input));
  ImGui::Button("Ok");

  ImGui::InputText("Stock2", second_stock_input, sizeof(second_stock_input));
  ImGui::Button("Ok");

  ImGui::InputText("Stock3", third_stock_input, sizeof(third_stock_input));
  ImGui::Button("Ok");
  ImGui::End();
}

void StockGeo::keyDown(KeyEvent event) { }

}  // namespace myapp
