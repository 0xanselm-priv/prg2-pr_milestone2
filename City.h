//
// Created by Niels Heissel on 27.11.18.
//



#ifndef PRG2_PR_MILESTONE2_CITY_H
#define PRG2_PR_MILESTONE2_CITY_H


#include <vector>
#include "Vertex.h"
using namespace std;




class City {
private:
    vector <float> coords;
    int id;
public:
    City(int x, int y, int id);

    float get_x(){
        return this->coords[0];
    }
    float get_y(){
        return this->coords[1];
    }
    int get_id(){
        return this->id;
    }
    vector <float> get_coords(){
        return this->coords;
    }

    void set_x(int x){
        this->coords[0] = x;
    }
    void set_y(int y){
        this->coords[1] = y;
    }
    void set_id(int id){
        this->id = id;
    }


// das addieren und subtrahieren von städten und vertexen ergibt das ergebnis des Vektors
    vector <float> operator+(Vertex& v){
        vector <float> result = {this->get_x() + v.get_x(), this->get_y() + v.get_y()};
        return result;
    }
    vector <float> operator+(City& c){
        vector <float> result = {this->get_x() + c.get_x(), this->get_y() + c.get_y()};
        return result;
    }
    vector <float> operator-(Vertex& v){
        vector <float> result = {this->get_x() - v.get_x(), this->get_y() - v.get_y()};
        return result;
    }
    vector <float> operator-(City& c){
        vector <float> result = {this->get_x() - c.get_x(), this->get_y() - c.get_y()};
        return result;
    }

    vector <float> operator*(int c){
        vector <float> result = {this->get_x() * c, this->get_y() * c};
        return result;
    }
};


#endif //PRG2_PR_MILESTONE2_CITY_H
