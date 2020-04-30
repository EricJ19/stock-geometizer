// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "stock_geometizer.h"

#include <cinder/app/App.h>

#include "../submodules/cpr/include/cpr/api.h"
#include "../submodules/cpr/include/cpr/auth.h"
#include "../submodules/cpr/include/cpr/cprtypes.h"
#include "../submodules/cpr/include/cpr/parameters.h"
#include <nlohmann/json.hpp>


namespace myapp {

using cinder::app::KeyEvent;

StockGeo::StockGeo() { }

void StockGeo::setup() {

}

void StockGeo::update() {
  auto test = cpr::Get(cpr::Url{"https://finnhub.io/api/v1/stock/eps-estimate?symbol=AMZN&freq=annual&token=bqhl2s7rh5rdcs9r2ovg"});

}

void StockGeo::draw() {

}

void StockGeo::keyDown(KeyEvent event) { }

}  // namespace myapp
