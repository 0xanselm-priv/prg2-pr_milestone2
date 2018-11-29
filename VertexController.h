//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H
#define PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H

#include <vector>
#include "Vertex.h"
using namespace std;


class VertexController {

public:
  VertexController(int j); // k is the number of cities
  Vertex vertex(int id);
  vector <Vertex> get_vertices() { return vertices_; }
  int id() { return id_; }
  void aply_delta(int id, vector <float> delta);
 private:
  vector <Vertex> vertices_;
  int id_;
};


#endif //PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H
