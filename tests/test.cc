// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Rand.h>
#include <mylibrary/finance_data.h>
#include <mylibrary/finance_geometry.h>

#include <catch2/catch.hpp>

TEST_CASE("Geometry class modifies geometry based on FinanceData",
    "[outer-color][FinanceData][Geometry]") {
  finance::FinanceData test_fin_data;

  const double kPriceQuote = 100;
  test_fin_data.SetPriceQuote(kPriceQuote);

  const double k3YrGrowth = 10;
  const double k26WeekPriceReturn = 10;
  test_fin_data.Set3YrRevGrowthRate(k3YrGrowth);
  test_fin_data.Set26WkPriceReturn(k26WeekPriceReturn);

  const double kStrongSell = 5;
  const double kStrongBuy = 5;
  const double kHold = 5;
  const double kSell = 5;
  const double kBuy = 5;
  test_fin_data.SetStrongSellRec(kStrongSell);
  test_fin_data.SetStrongBuyRec(kStrongBuy);
  test_fin_data.SetHoldRec(kHold);
  test_fin_data.SetSellRec(kSell);
  test_fin_data.SetBuyRec(kBuy);

  geometry::Geometry test_geo;

  SECTION("Sets outer colors based on stock data") {
    test_geo.SetOuterColors(test_fin_data);

    // Based on stock data, outer geometry should be green.
    // This is because growth and return is positive.
    double expected_red = 0;
    double expected_blue = 0;
    // Decimal values due to precision of double stored in outer colors.
    double expected_green = 0.7733333333333333;

    REQUIRE(test_geo.GetOuterRedColor() == expected_red);
    REQUIRE(test_geo.GetOuterBlueColor() == expected_blue);
    REQUIRE(test_geo.GetOuterGreenColor() == expected_green);
  }

  SECTION("Sets inner colors based on stock data") {
    test_geo.SetInnerColors(test_fin_data);

    // Based on stock data, inner geometry should be yellow.
    // This is due to equal sell, buy, etc. values being equal.
    double expected_red = 0.4;
    double expected_blue = 0;
    double expected_green = 0.4;

    REQUIRE(test_geo.GetInnerRedColor() == 0.4);
    REQUIRE(test_geo.GetInnerBlueColor() == 0);
    REQUIRE(test_geo.GetInnerGreenColor() == 0.4);
  }

  SECTION("Sets outer edges based on stock data") {
    test_geo.SetOuterEdges(test_fin_data);

    int expected_outer_edge_numb = 5;

    REQUIRE(test_geo.GetOuterEdgeNumber() == expected_outer_edge_numb);
  }

  SECTION("Sets inner edges based on stock data") {
    test_geo.SetInnerEdges(test_fin_data);

    int expected_inner_edge_numb = 3;

    REQUIRE(test_geo.GetInnerEdgeNumber() == expected_inner_edge_numb);
  }
}