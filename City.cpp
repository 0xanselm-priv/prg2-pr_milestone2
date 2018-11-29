//
// Created by Niels Heissel on 27.11.18.
//

#include "City.h"
#include "Vertex.h"


City::City(float x, float y, int id) {
    set_x(x);
    set_y(y);
    set_id(id);
}

float City::operator%(Vertex& v){
        float x = (this->x() - v.x());
        float y = (this->y() - v.y());
        return pow(sqrt(pow(x, 2) + pow(y, 2)),2);
}

Vertex City::operator-(City& c){
        Vertex result = {this->x() - c.x(), this->y() - c.y(), -1};
        return result;
}		

Vertex City::operator*(float c){
	return {this->x() * c, this->y() * c, -1};
}

Vertex City::operator+(Vertex& v){
        Vertex result = {this->x() + v.x(), this->y() + v.y(), -1};
        return result;
}
    Vertex City::operator+(City& c){
        Vertex result = {this->x() + c.x(), this->y() + c.y(), -1};
        return result;
}
    Vertex City::operator-(Vertex& v){
        Vertex result = {this->x() - v.x(), this->y() - v.y(), -1};
        return result;
}