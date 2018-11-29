//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_CITYCONTROLLER_H
#define PRG2_PR_MILESTONE2_CITYCONTROLLER_H

#include "City.h"
#include <vector>
using namespace std;

class CityController {
private:
    vector <City> cities;
    int id;
public:
    CityController();

    int get_id(){
        return this->id;
    }
    City get_city(int id){
        return this->cities[id];
    }

    void add_city(float x, float y); // increment id every call ----- look for minimalabstand
    vector <City> get_cities(){
        return this->cities;
    }
};


#endif //PRG2_PR_MILESTONE2_CITYCONTROLLER_H
