//
// Created by Eric Jin on 4/24/20.
//
#include <mylibrary/finance_data.h>
#include <mylibrary/finance_geometry.h>

void geometry::Geometry::SetOuterColors(finance::FinanceData fin_data) {
  // Turn price return as a growth rate.
  int deci_to_percent = 100;
  double _26_wk_price_growth_rate
    = (fin_data.Get26WkPriceReturn() / fin_data.GetPriceQuote())
        * deci_to_percent;

  double weighted_index = kPriceReturnWeight * _26_wk_price_growth_rate
                        + kRevGrowthWeight * fin_data.Get3YrRevGrowthRate();

  // Default values.
  double unscaled_red = kMinGrowthRate;
  double unscaled_green = kMinGrowthRate;
  // Blue color is not needed but can be changed.
  double unscaled_blue = kMinGrowthRate;

  // This is to create a range of possible values near weighted_index = 0 for
  // the color to be a yellow gradient.
  double const kYellowBounds = 8.0;
  // Create red, green, or yellow shade depending on index.
  if (-kYellowBounds < weighted_index && weighted_index < kYellowBounds) {
    // Yellow gradient is created here.
    unscaled_red = weighted_index;
    unscaled_green = weighted_index;

  } if (weighted_index < 0) {
    unscaled_red = weighted_index;

  } else if (weighted_index > 0) {
    unscaled_green = weighted_index;
  }

  // Ensure unscaled values are not larger than maximum threshold.
  if (unscaled_red > kMaxGrowthRate) {
    unscaled_red = kMaxGrowthRate;
  }

  if (unscaled_green > kMaxGrowthRate) {
    unscaled_green = kMaxGrowthRate;
  }

  if (unscaled_blue > kMaxGrowthRate) {
    unscaled_blue = kMaxGrowthRate;
  }

  // Scales values to between 0 and 1.
  double scaled_red = (unscaled_red - kMinGrowthRate)
                    / (kMaxRecNumb - kMinGrowthRate);
  double scaled_green = (unscaled_green - kMinGrowthRate)
                      / (kMaxRecNumb - kMinGrowthRate);
  double scaled_blue = (unscaled_blue - kMinGrowthRate)
                     / (kMaxRecNumb - kMinGrowthRate);

  outer_red_value = scaled_red;
  outer_green_value = scaled_green;
  outer_blue_value = scaled_blue;
}

void geometry::Geometry::SetOuterEdges(finance::FinanceData fin_data) {
  // Turn price return as a growth rate.
  int deci_to_percent = 100;
  double _26_wk_price_growth_rate
    = (fin_data.Get26WkPriceReturn() / fin_data.GetPriceQuote())
        * deci_to_percent;

  // Note: Price return and growth weight can be positive or negative.
  double unscaled_edge_number
    = kPriceReturnWeight * _26_wk_price_growth_rate
        + kStrongRecWeight * fin_data.Get3YrRevGrowthRate();

  // Scale edge_number between 0 and 8 (max edges).
  double scaled_edge_number
      = (unscaled_edge_number / kMaxRecNumb) * kMaxOuterEdgeNumb;

  // Ensure scaled value is at least 3 to create a valid polygon shape.
  if (scaled_edge_number < kMinEdgeNumb) {
    scaled_edge_number = kMinEdgeNumb;
  }

  outer_edge_number = (int) scaled_edge_number;
}

double geometry::Geometry::GetOuterRedColor() {
  return this->outer_red_value;
}

double geometry::Geometry::GetOuterGreenColor() {
  return this->outer_green_value;
}

double geometry::Geometry::GetOuterBlueColor() {
  return this->outer_blue_value;
}

double geometry::Geometry::GetOuterEdgeNumber() {
  return this->outer_edge_number;
}


void geometry::Geometry::SetInnerColors(finance::FinanceData fin_data) {
  double unscaled_red = kStrongRecWeight * fin_data.GetStrongSellRec()
                      + fin_data.GetSellRec()
                      + fin_data.GetHoldRec();
  double unscaled_green = kStrongRecWeight * fin_data.GetStrongBuyRec()
                          + fin_data.GetBuyRec()
                          + fin_data.GetHoldRec();
  // Blue color is not needed but can be changed.
  double unscaled_blue = 0.0;

  // Ensure unscaled values are not larger than maximum threshold.
  if (unscaled_red > kMaxRecNumb) {
    unscaled_red = kMaxRecNumb;
  }

  if (unscaled_green > kMaxRecNumb) {
    unscaled_green = kMaxRecNumb;
  }

  if (unscaled_blue > kMaxRecNumb) {
    unscaled_blue = kMaxRecNumb;
  }

  // Scales values to between 0 and 1.
  double scaled_red = unscaled_red / kMaxRecNumb;
  double scaled_green = unscaled_green / kMaxRecNumb;
  double scaled_blue = unscaled_blue / kMaxRecNumb;

  inner_red_value = scaled_red;
  inner_green_value = scaled_green;
  inner_blue_value = scaled_blue;
}

void geometry::Geometry::SetInnerEdges(finance::FinanceData fin_data) {
  double unscaled_edge_number = kStrongRecWeight * fin_data.GetStrongBuyRec()
                         + fin_data.GetBuyRec()
                         - fin_data.GetSellRec()
                         - kStrongRecWeight * fin_data.GetStrongSellRec();

  // Scale edge_number between 0 and 10 (max edges).
  double scaled_edge_number
    = (unscaled_edge_number / kMaxRecNumb) * kMaxInnerEdgeNumb;

  // Ensure scaled value is at least 3 to create a valid polygon shape.
  if (scaled_edge_number < kMinEdgeNumb) {
    scaled_edge_number = kMinEdgeNumb;
  }

  inner_edge_number = (int) scaled_edge_number;
}

double geometry::Geometry::GetInnerRedColor() {
  return this->inner_red_value;
}

double geometry::Geometry::GetInnerGreenColor() {
  return this->inner_green_value;
}

double geometry::Geometry::GetInnerBlueColor() {
  return this->inner_blue_value;
}

double geometry::Geometry::GetInnerEdgeNumber() {
  return this->inner_edge_number;
}

