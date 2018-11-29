//
// Created by Niels Heissel on 27.11.18.
//



#ifndef PRG2_PR_MILESTONE2_CITY_H
#define PRG2_PR_MILESTONE2_CITY_H

#include "Vertex.h"
#include <cmath>
#include <vector>

class City : public Vertex {
 public:
  using Vertex::Vertex;
  float operator%(Vertex& v);
};

#endif //PRG2_PR_MILESTONE2_CITY_H
