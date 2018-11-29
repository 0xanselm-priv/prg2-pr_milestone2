//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_VERTEX_H

#define PRG2_PR_MILESTONE2_VERTEX_H
#include <vector>

#include <cmath>


using namespace std;

class Vertex {
 public:
  Vertex(float x, float y, int id);

  float x() { return coords_[0]; }
  float y() { return coords_[1]; }
  int id() { return id_; }
  std::vector <float> coords() { return coords_; }

  void set_coords(vector <float> coords) { coords = coords; }
  void set_x(float x) { coords_[0] = x; }
  void set_y(float y) { coords_[1] = y; }
  void set_id(int id) { id_ = id; }
// overloaded operators for calculations
  Vertex operator+(Vertex& v);
  Vertex operator-(Vertex& v);
  Vertex operator*(float c);
  float operator%(Vertex& v);
 private:
  vector <float> coords_;
  int id_;
};


#endif //PRG2_PR_MILESTONE2_VERTEX_H
