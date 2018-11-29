//
// Created by Niels Heissel on 27.11.18.
//

#include "City.h"
#include "Vertex.h"

float City::operator%(Vertex& v){
        float x = (this->x() - v.x());
        float y = (this->y() - v.y());
        return pow(sqrt(pow(x, 2) + pow(y, 2)),2);
}