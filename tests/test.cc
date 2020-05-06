// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/finance_data.h>
#include <mylibrary/finance_geometry.h>

#include <catch2/catch.hpp>

TEST_CASE("Geometry class modifies geometry based on FinanceData",
    "[outer-color][FinanceData][Geometry]") {
  finance::FinanceData test_fin_data;

  const double kPriceQuote = 200;
  test_fin_data.SetPriceQuote(kPriceQuote);

  const double k3YrGrowthRate = 50;
  const double k26WeekPriceReturn = 10;
  test_fin_data.Set3YrRevGrowthRate(k3YrGrowthRate);
  test_fin_data.Set26WkPriceReturn(k26WeekPriceReturn);

  const double kStrongSell = 5;
  const double kStrongBuy = 10;
  const double kHold = 10;
  const double kSell = 2;
  const double kBuy = 5;
  test_fin_data.SetStrongSellRec(kStrongSell);
  test_fin_data.SetStrongBuyRec(kStrongBuy);
  test_fin_data.SetHoldRec(kHold);
  test_fin_data.SetSellRec(kSell);
  test_fin_data.SetBuyRec(kBuy);

  geometry::Geometry test_geo;
  test_geo.SetOuterColors(test_fin_data);

  SECTION("Sets outer colors based on stock data") {

  }

  SECTION("Sets inner colors based on stock data") {

  }

  SECTION("Sets outer edges based on stock data") {

  }

  SECTION("Sets inner edges based on stock data") {

  }
}