//
// Created by Niels Heissel on 27.11.18.
//



#ifndef PRG2_PR_MILESTONE2_CITY_H
#define PRG2_PR_MILESTONE2_CITY_H

#include "Vertex.h"
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

class City {
private:
    vector <float> coords {0,0};
    int id;
public:
    City(float x, float y, int id);
    float get_x() { return this->coords[0]; }
    float get_y() { return this->coords[1]; }
    int get_id() { return this->id; }
    vector<float> get_coords() { return this->coords; }

    void set_coords(vector <float> coords) { this->coords = coords; }
    void set_x(float x) { this->coords[0] = x; }
    void set_y(float y) { this->coords[1] = y; }
    void set_id(int id) { this->id = id; }

// das addieren und subtrahieren von städten und vertexen ergibt das ergebnis des Vektors
    Vertex operator+(Vertex& v);
    Vertex operator+(City& c);
    Vertex operator-(Vertex& v);
    Vertex operator-(City& c);
    Vertex operator*(float c);
    float operator%(Vertex& v);
    float operator%(City& v);
};


#endif //PRG2_PR_MILESTONE2_CITY_H
