//
// Created by Niels Heissel on 27.11.18.
//

#include "City.h"
#include "Vertex.h"
#include <iostream>
using namespace std;


City::City(float x, float y, int id) {
    set_x(x);
    set_y(y);
    set_id(id);
}

Vertex City::operator+(Vertex& v){
        Vertex result = {this->get_x() + v.get_x(), this->get_y() + v.get_y(), -1};
        return result;
}
Vertex City::operator+(City& c){
    Vertex result = {this->get_x() + c.get_x(), this->get_y() + c.get_y(), -1};
    return result;
}
Vertex City::operator-(Vertex& v){
    Vertex result = {this->get_x() - v.get_x(), this->get_y() - v.get_y(), -1};
    return result;
}
Vertex City::operator-(City& c){
    Vertex result = {this->get_x() - c.get_x(), this->get_y() - c.get_y(), -1};
    return result;
}

Vertex City::operator*(float c){
    Vertex result = {this->get_x() * c, this->get_y() * c, -1};
    return result;
}

float City::operator%(Vertex& v){
    float x = (this->get_x() - v.get_x());
    float y = (this->get_y() - v.get_y());
    return pow(sqrt(pow(x, 2) + pow(y, 2)),0.5);
}

float City::operator%(City& v){
    float x = (this->get_x() - v.get_x());
    float y = (this->get_y() - v.get_y());
    return pow(sqrt(pow(x, 2) + pow(y, 2)),0.5);
}