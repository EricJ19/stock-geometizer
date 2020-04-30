// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "stock_geometizer.h"

#include <cinder/app/App.h>

#include "cpr/api.h"
#include "cpr/auth.h"
#include "cpr/cprtypes.h"
#include "cpr/parameters.h"
#include "nlohmann/json.hpp"
#include "../blocks/Cinder-ImGui/include/CinderImGui.h"

namespace myapp {

using cinder::app::KeyEvent;

StockGeo::StockGeo() {
}

void StockGeo::setup() {
}

void StockGeo::update() {
  cpr::Response response = cpr::Get(cpr::Url{"https://finnhub.io/api/v1/stock/eps-estimate?symbol=AMZN&freq=annual&token=bqhl2s7rh5rdcs9r2ovg"});
  nlohmann::json json_response = response.text;
}

void StockGeo::draw() {

}

void StockGeo::keyDown(KeyEvent event) { }

}  // namespace myapp
