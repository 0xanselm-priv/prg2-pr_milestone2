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
        Vertex result = {this->get_x() + v.get_x(), this->get_y() + v.get_y(), -1};
        return result;
}

Vertex Vertex::operator-(Vertex& v){
    Vertex result = {this->get_x() - v.get_x(), this->get_y() - v.get_y(), -1};
    return result;
}

Vertex Vertex::operator*(float c){
    Vertex result = {this->get_x() * c, this->get_y() * c, -1};
    return result;
}