//
// Created by Niels Heissel on 27.11.18.
//

#include "VertexController.h"
#include "Vertex.h"
#include <vector>
using namespace std;

Vertex VertexController::vertex(int id){
    return this->vertices[id];
}

void aply_delta(int id, vector <float> delta){
    Vertex vertex = this->vertices[id];
    vector <float> new_coords {vertex.x() + delta[0], vertex.y() + delta[1]};
    vertex.set_coords(new_coords);
  }
