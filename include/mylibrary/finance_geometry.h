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
  // Price return weight is favored as it represents shorter term changes which
  // may be more relevant for short-term investors.
  const double kPriceReturnWeight = 0.9;
  const double kRevGrowthWeight = 0.7;
  // Weight based on real value.
  const double kStrongRecWeight = 2.0;

  // Below are Max/min const values for scaling the edge number
  // and color gradient.
  // Otherwise, edge number and color gradient could vary widely, making it's
  // geometry potentially hard to understand (ex. edge number of 3000).
  // "double" type is used for division with other double values.

  // This is a reasonable, arbitrarily large number based on observed.
  // sample of API responses
  const double kMaxRecNumb = 30;
  // Max/Min growth rate is for _3_yr_rev_growth_rate and _26_wk_price_return.
  // These are arbitrarily and small/large percentages
  // that would show clear differences in color for typical stocks.
  const double kMinGrowthRate = -100;
  const double kMaxGrowthRate = 100;

  // Outer edge number is larger than inner as
  // outer shape is related to percentage, which has larger range
  // than recommendation number used for inner edge number.
  const double kMaxOuterEdgeNumb = 10;
  const double kMaxInnerEdgeNumb = 10;
  // Minimum polygon shape is a triangle.
  const double kMinEdgeNumb = 3;

  // RGB values for the outer geometry.
  double outer_red_value;
  double outer_green_value;
  double outer_blue_value;

  // Number of edges forming the outer shape.
  // More edges mean more positive price return and growth rate.
  // less edges more more negative price return and growth rate.
  int outer_edge_number;

  // RGB values for the inner geometry.
  double inner_red_value;
  double inner_green_value;
  double inner_blue_value;

  // Number of edges forming the inner shape.
  // More edges mean more buy recommendations
  // less edges more sell recommendations.
  int inner_edge_number;

 public:
  //===========================================================================
  // Note: outer and inner calculations represent the desirability of stocks.
  //
  // The more edges for both inner and outer calculations, the more desirable,
  // with more growth, return, buy recommendations etc.
  //
  // For both inner and outer calculations:
  // The more red, the more undesirable
  // (eg. buy_rec is low, 3 Year Growth is negative).
  // The more green, the more desirable.
  // Yellow represents a mix of desirability and undesirability.
  // Blue color is not necessary although it is an option than can be modified.
  //===========================================================================

  // Outer Colors and Edges are determined by: 26 Week price return,
  // price quote, and 3 year growth rate. These are extracted
  // from FinanceData Object.

  // For both SetOuterColors and SetOuterEdges:
  // fin_data - financial data set associated with this current Geometry class.
  void SetOuterColors(finance::FinanceData fin_data);
  void SetOuterEdges(finance::FinanceData fin_data);
  double GetOuterRedColor();
  double GetOuterGreenColor();
  double GetOuterBlueColor();
  double GetOuterEdgeNumber();

  // Inner Colors and Edges are determined by: buy, sell, hold, strong buy,
  // and strong sell recommendations. These are extracted
  // from FinanceData Object.

  // For both SetInnerColors and SetInnerEdges:
  // fin_data - financial data set associated with this current Geometry class.
  void SetInnerColors(finance::FinanceData fin_data);
  void SetInnerEdges(finance::FinanceData fin_data);
  double GetInnerRedColor();
  double GetInnerGreenColor();
  double GetInnerBlueColor();
  double GetInnerEdgeNumber();
};

} // namespace geometry

#endif  // FINALPROJECT_GEOMETRY_DATA_H
