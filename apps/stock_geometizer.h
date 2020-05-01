// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <imgui.h>
#include <mylibrary/finance_data.h>
#include <mylibrary/finance_geometry.h>

#include <array>

namespace myapp {

// This segments the screen into different parts to put the different shape center in.
const int kWindowSegmentNumb = 5;

// Used to ensure each geometrical shape is vertically centered.
const double kHalf = 2.0;

// Mac number of geometrical shapes that can be displaced.
const int kMaxNumbOfGeos = 3;

// These are for changing the sizes of the geometrical shapes.
const int kInnerRadius = 100;
const int kOuterRadius = 175;

// These distinguish which geometrical shape or finance data set
// the code is dealing with.
const int kFirstGeoNumb = 1;
const int kSecondGeoNumb = 2;
const int kThirdGeoNumb = 3;

// This is for the base URL for all API calls.
const std::string kAPIBase = "https://finnhub.io/api/v1";

// Key to use finhubb.io API
const std::string kAPIKey = "bqhl2s7rh5rdcs9r2ovg";

// Beginning of URLs for different API calls for finance metrics.

// Beginning call for data on price quote of stock.
const std::string kPriceQuoteBeginURL = kAPIBase + "/quote?symbol=";
// Beginning (as user's input splits the full URL) call for data on
// 26 Week Price Return and 3 Year Revenue Growth Rate.
const std::string kMetricsBeginURL = kAPIBase + "/stock/metric?symbol=";
// Beginning call for data on number of:
// buy, sell, hold, strong buy, and strong sell recommendations.
const std::string kRecommendationBeginURL = kAPIBase
                                          + "/stock/recommendation?symbol=";

// Ending of URLs for different API calls for finance metrics.

// Used for Price Quote.
const std::string kPriceQuoteEndURL = "&token=" + kAPIKey;
// Used for 26 Week price return.
const std::string kPriceMetricEndURL = "&metric=price&token=" + kAPIKey;
// Used for 3 year growth rate.
const std::string kGrowthMetricEndURL = "&metric=growth&token=" + kAPIKey;
// Used for buy, sell, hold, strong buy, and strong sell recommendations.
const std::string kRecommendationsEndURL = "&token=" + kAPIKey;

class StockGeo : public cinder::app::App {
 private:
  //TODO:: Try to change these to vectors or some other wrapper.
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
  // user_input is the input to the ImGui::InputText
  // geometry_number represents which geometry from which call being analyzed
  // from 1 to 3.
  void ReceiveAPICallData(const std::string& user_input, int geometry_number);
  // fin_data represents which financial data set (ex. first_fin_data) is
  // being analyazed (this corresponds to geometry).
  // geometry_data represents which geometry data set being analyzed.
  void SetFinanceData(finance::FinanceData& fin_data,
                      geometry::Geometry& geo_data);
  // geometry_data represents which geometry data set being analyzed.
  // geo_number represents which geometry shape is being analyzed (from 1 to 3)
  void DrawInnerShape(geometry::Geometry& geo_data, int geo_numb);
  // geometry_data represents which geometry data set being analyzed.
  // geo_number represents which geometry shape is being analyzed (from 1 to 3)
  void DrawOuterShape(geometry::Geometry& geo_data, int geo_numb);

};

//int callback(ImGuiTextEditCallbackData* data);

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
