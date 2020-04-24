//
// Created by Eric Jin on 4/24/20.
//
#include <mylibrary/finance_geometry.h>

void geometry::Geometry::SetOuterColors(double price_quote,
                                        double _26_wk_price_return,
                                        double _3_yr_rev_growth_rate) {
  outer_red_value = 2;
  outer_green_value = 2;
  // Blue color is not needed.
  outer_blue_value = 0;
}

void geometry::Geometry::SetOuterEdges(double price_quote,
                                       double _26_wk_price_return,
                                       double _3_yr_rev_growth_rate) {

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


void geometry::Geometry::SetInnerColors(int buy_rec,
                                        int sell_rec,
                                        int hold_rec,
                                        int strong_buy_rec,
                                        int strong_sell_rec) {
  double unscaled_red = kStrongRecWeight * strong_sell_rec
                      + sell_rec
                      + hold_rec;
  double unscaled_green = kStrongRecWeight * strong_buy_rec
                          + buy_rec
                          + hold_rec;
  // Blue color is not needed but can be changed.
  double unscaled_blue = 0.0;

  // Ensure unscaled values are not larger than maximum threshold.
  if (unscaled_red > kMaxRecNumb) {
    unscaled_red = kMaxRecNumb;
  }

  if (unscaled_green > kMaxRecNumb) {
    unscaled_red = kMaxRecNumb;
  }

  if (unscaled_green > kMaxRecNumb) {
    unscaled_red = kMaxRecNumb;
  }

  // Scales values to between 0 and 1.
  double scaled_red = unscaled_red / kMaxRecNumb;
  double scaled_green = unscaled_green / kMaxRecNumb;
  double scaled_blue = unscaled_blue / kMaxRecNumb;

  inner_red_value = scaled_red;
  inner_green_value = scaled_green;
  inner_blue_value = scaled_blue;
}

void geometry::Geometry::SetInnerEdges(int buy_rec,
                                       int sell_rec,
                                       int strong_buy_rec,
                                       int strong_sell_rec) {
  double unscaled_edge_number = kStrongRecWeight * strong_buy_rec
                         + buy_rec
                         - sell_rec
                         - kStrongRecWeight * strong_sell_rec;

  // Scale edge_number between 0 and 10 (max edges).
  double scaled_edge_number
    = (unscaled_edge_number / kMaxRecNumb) * kMaxEdgeNumb;

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

