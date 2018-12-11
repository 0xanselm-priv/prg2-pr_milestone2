//
// Created by Niels Heissel on 27.11.18.
//

#include "Vertex.h"
#include "City.h"

Vertex::Vertex(float x, float y, int id) {
    set_x(x);
    set_y(y);
    set_id(id);
}

Vertex Vertex::operator+(Vertex& v){
    Vertex result = {this->x() + v.x(), this->y() + v.y(), -1};
    return result;
}

Vertex Vertex::operator-(Vertex& v){
    Vertex result = {this->x() - v.x(), this->y() - v.y(), -1};
    return result;
}

Vertex Vertex::operator*(float c){
	return {this->x() * c, this->y() * c, -1};
}