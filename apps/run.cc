// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "stock_geometizer.h"

using cinder::app::App;
using cinder::app::RendererGl;


namespace stockgeoapp {

const int kSamples = 8;
const int kWidth = 1500;
const int kHeight = 800;

void SetUp(App::Settings* settings) {
  settings->setFrameRate(60);
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("Stock Geometizer");
}

}  // namespace stockgeoapp


// This is a macro that runs the application.
CINDER_APP(stockgeoapp::StockGeo,
           RendererGl(RendererGl::Options().msaa(stockgeoapp::kSamples)),
           stockgeoapp::SetUp)
