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
  void SetOuterColors();
  void SetOuterEdges();

  void SetInnerColors();
  void SetInnerEdges();
};

} // namespace geometry

#endif  // FINALPROJECT_GEOMETRY_DATA_H
