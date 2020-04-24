//
// Created by Eric Jin on 4/24/20.
//

#ifndef FINALPROJECT_GEOMETRY_DATA_H
#define FINALPROJECT_GEOMETRY_DATA_H

namespace geometry {

class Geometry {
 private:
  // RGB values for the outer geometry.
  int outer_red_value;
  int outer_green_value;
  int outer_blue_value;

  // Number of edges forming the outer shape.
  int outer_edge_number;

  // RGB values for the inner geometry.
  int inner_red_value;
  int inner_green_value;
  int inner_blue_value;

  // Number of edges forming the inner shape.
  int inner_edge_number;

 public:
  void SetOuterColors(double _26_wk_price_return,
                      double _3_yr_rev_growth_rate);
  void SetOuterEdges(double _26_wk_price_return,
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
