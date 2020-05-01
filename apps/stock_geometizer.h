// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <imgui.h>
#include <mylibrary/finance_data.h>
#include <mylibrary/finance_geometry.h>

#include <array>

namespace myapp {

class StockGeo : public cinder::app::App {
 private:
  const std::string kAPIBase = "https://finnhub.io/api/v1";

  // These are for ImGui Window
  char first_input_chars[5];
  char second_input_chars[5];
  char third_input_chars[5];
  std::string first_input_str;
  std::string second_input_str;
  std::string third_input_str;

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
  //void SetUserInputToString(std::string input_str, std::vector<char> input_chars);
  void CreateStockWindow();
  void DrawGeo();
};

int callback(ImGuiTextEditCallbackData* data);

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
