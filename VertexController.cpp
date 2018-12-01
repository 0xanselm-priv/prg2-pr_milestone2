//
// Created by Niels Heissel on 27.11.18.
//

#include "VertexController.h"
#include "Vertex.h"
#include <vector>
using namespace std;

VertexController::VertexController(int j, float cv_ratio, float radius, ) {
    this->cv_ratio = cv_ratio;
    this->city_num = j;
    this->radius = radius;

    //wie findet man den mittelpunkt raus?

}

Vertex VertexController::get_vertex(int id){
    return this->vertices[id];
}

