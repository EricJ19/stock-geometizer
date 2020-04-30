// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <mylibrary/finance_data.h>
#include <mylibrary/finance_geometry.h>

namespace myapp {

class StockGeo : public cinder::app::App {
 private:
  const std::string kAPIBase = "https://finnhub.io/api/v1";

  // These are for ImGui Window
  char first_stock_input[5];
  char second_stock_input[5];
  char third_stock_input[5];
  std::string first_stock_call;
  std::string second_stock_call;
  std::string third_stock_call;

  // These represent finance data for each of the three stock options.
  finance::FinanceData first_fin_data;
  finance::FinanceData second_fin_data;
  finance::FinanceData third_fin_data;

  // These represent geometry data for each of the three stock options.
  // This corresponds with the finance data.
  geometry::Geometry first_geo;
  geometry::Geometry second_geo;
  geometry::Geometry third_geo;
 public:
  StockGeo();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void ResetGame();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
