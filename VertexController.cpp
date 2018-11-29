//
// Created by Niels Heissel on 27.11.18.
//

#include "VertexController.h"
#include "Vertex.h"
#include <vector>
using namespace std;

Vertex VertexController::vertex(int id){
    return this->vertices_[id];
}

void VertexController::ApplyDelta(int id, vector <float> delta){
    Vertex vertex = this->vertices_[id];
    vector <float> new_coords {vertex.x() + delta[0], vertex.y() + delta[1]};
    vertex.set_coords(new_coords);
}

VertexController::VertexController(int j) : id_(0), vertices_(std::vector < Vertex > ()) {}