// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <imgui.h>
#include <mylibrary/finance_data.h>
#include <mylibrary/finance_geometry.h>

#include <array>
#include <nlohmann/json.hpp>

namespace myapp {

// Used to ensure each geometrical shape is vertically centered.
const double kHalf = 2.0;

// Max number of geometrical shapes that can be displaced.
const int kMaxNumbOfGeos = 3;

// These are for changing the sizes of the geometrical shapes.
const int kInnerRadius = 85;
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
  // Represents the y-position of the vertical middle of the app window.
  double mid_window_height{};
  // Represents the x-position of a third of the app window width.
  double third_of_window_width{};

  //TODO: Try to change these to vectors or some other wrapper.

  // These are for ImGui::InputText.
  char first_input_chars[7];
  char second_input_chars[7];
  char third_input_chars[7];
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
  void CreateStockWindow();
  void DrawGeo();

  // Calls and Receives API data, storing them in FinanceData
  // and Geometry objects.
  // user_input is the input to the ImGui::InputText
  // geo_numb represents which geometry from which call being analyzed
  // from 1 to 3.
  void ReceiveAPICallData(const std::string& user_input, int geo_numb);

  // Small helper function that finds the appropriate financial
  // data set to analyze.
  // geo_numb represents which geometry shape is being analyzed (from 1 to 3).
  finance::FinanceData& FindFinSetToAnalyze(const int& geo_numb);

  // Using the responses from API calls, populates FinanceData object fields.
  // fin_data represents which financial data set (ex. first_fin_data) is
  // being analyzed (this corresponds to which geometry is being analyzed).
  // parse_price_quote - API JSON response for price quote.
  // parse_price_metrics - API JSON response for price metrics.
  // parse_growth_metrics - API JSON response for growth metrics.
  // parse_recommendations - API JSON response for recommendations.
  // fin_data is modified based on API calls.
  void SetFinanceData(finance::FinanceData& fin_data,
                      const nlohmann::json& parse_price_quote,
                      const nlohmann::json& parse_price_metrics,
                      const nlohmann::json& parse_growth_metrics,
                      const nlohmann::json & parse_recommendations);

  // Sets color and edge number of inner and outer shape of a shape.
  // fin_data represents which financial data set is being analyazed.
  // geometry_data represents which geometry data set being analyzed.
  // geo_data is modified based on fin_data.
  void SetGeoData(finance::FinanceData& fin_data,
                      geometry::Geometry& geo_data);

  // geometry_data represents which geometry data set being analyzed.
  // geo_numb represents which geometry shape is being analyzed (from 1 to 3).
  void DrawInnerShape(geometry::Geometry& geo_data, int geo_numb);

  // geometry_data represents which geometry data set being analyzed.
  // geo_numb represents which geometry shape is being analyzed (from 1 to 3).
  void DrawOuterShape(geometry::Geometry& geo_data, int geo_numb);
};

//int callback(ImGuiTextEditCallbackData* data);

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
