// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "stock_geometizer.h"

#include <cinder/app/App.h>

#include "../submodules/cpr/include/cpr/api.h"
#include "../submodules/cpr/include/cpr/auth.h"
#include "../submodules/cpr/include/cpr/cprtypes.h"
#include "../submodules/cpr/include/cpr/parameters.h"

namespace myapp {

using cinder::app::KeyEvent;

StockGeo::StockGeo() { }

void StockGeo::setup() {

}

void StockGeo::update() {
//  auto first = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
//                    cpr::Authentication{"user", "pass"},
//                    cpr::Parameters{{"anon", "true"}, {"key", "value"}});
}

void StockGeo::draw() { }

void StockGeo::keyDown(KeyEvent event) { }

}  // namespace myapp
