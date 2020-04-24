//
// Created by Eric Jin on 4/24/20.
//

#ifndef FINALPROJECT_GEOMETRY_DATA_H
#define FINALPROJECT_GEOMETRY_DATA_H

namespace geometry {

class Geometry {
 private:
  // Weighting used to skew geometric shape in favor of certain financial
  // measures more than others.

  // Weight based on percentage.
  const double kPriceReturnWeight = 0.7;
  const double kRevGrowthWeight = 0.3;
  // Weight based on real value.
  const double kStrongRecWeight = 2.0;

  // Max/min values for scaling purposes.
  // Max Rec is arbitrarily large.
  // "double" type is used for division with other double values.
  const double kMaxRecNumb = 35;


  // RGB values for the outer geometry.
  double outer_red_value;
  double outer_green_value;
  double outer_blue_value;

  // Number of edges forming the outer shape.
  int outer_edge_number;

  // RGB values for the inner geometry.
  double inner_red_value;
  double inner_green_value;
  double inner_blue_value;

  // Number of edges forming the inner shape.
  int inner_edge_number;

 public:
  // Note: outer and inner calculates represent the desirability of stocks.
  // The more red, the more undesirable (eg. buy_rec is low),
  // The more green, the more desirable.
  // Yellow represents a mix of desirability and undesirability.
  // Blue color is not necessary although it is an option than can be modified.

  void SetOuterColors(double price_quote,
                      double _26_wk_price_return,
                      double _3_yr_rev_growth_rate);
  void SetOuterEdges(double price_quote,
                     double _26_wk_price_return,
                     double _3_yr_rev_growth_rate);
  int GetOuterRedColor();
  int GetOuterGreenColor();
  int GetOuterBlueColor();
  int GetOuterEdgeNumber();

  void SetInnerColors(int buy_rec,
                      int sell_rec,
                      int hold_rec,
                      int strong_buy_rec,
                      int strong_sell_rec);
  void SetInnerEdges(int buy_rec,
                     int sell_rec,
                     int hold_rec,
                     int strong_buy_rec,
                     int strong_sell_rec);
  int GetInnerRedColor();
  int GetInnerGreenColor();
  int GetInnerBlueColor();
  int GetInnerEdgeNumber();
};

} // namespace geometry

#endif  // FINALPROJECT_GEOMETRY_DATA_H
