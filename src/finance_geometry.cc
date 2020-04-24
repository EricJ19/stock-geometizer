//
// Created by Eric Jin on 4/24/20.
//
#include <mylibrary/finance_geometry.h>

void geometry::Geometry::SetOuterColors(double _26_wk_price_return,
                                        double _3_yr_rev_growth_rate) {

}

void geometry::Geometry::SetOuterEdges(double _26_wk_price_return,
                                       double _3_yr_rev_growth_rate) {

}

int geometry::Geometry::GetOuterRedColor() {
  return this->outer_red_value;
}

int geometry::Geometry::GetOuterGreenColor() {
  return this->outer_green_value;
}

int geometry::Geometry::GetOuterBlueColor() {
  return this->outer_blue_value;
}

int geometry::Geometry::GetOuterEdgeNumber() {
  return this->outer_edge_number;
}


void geometry::Geometry::SetInnerColors(int buy_rec,
                                        int sell_rec,
                                        int hold_rec,
                                        int strong_buy_rec,
                                        int strong_sell_rec) {

}

void geometry::Geometry::SetInnerEdges(int buy_rec,
                                       int sell_rec,
                                       int hold_rec,
                                       int strong_buy_rec,
                                       int strong_sell_rec) {

}

int geometry::Geometry::GetInnerRedColor() {
  return this->inner_red_value;
}

int geometry::Geometry::GetInnerGreenColor() {
  return this->inner_green_value;
}

int geometry::Geometry::GetInnerBlueColor() {
  return this->inner_blue_value;
}

int geometry::Geometry::GetInnerEdgeNumber() {
  return this->inner_edge_number;
}

