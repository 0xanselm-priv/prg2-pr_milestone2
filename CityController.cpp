//
// Created by Niels Heissel on 27.11.18.
//

#include "CityController.h"
#include "City.h"
#include <iostream>
using namespace std;

void CityController::add_city(float x, float y) {

    City city {x, y, id};
    this->cities.push_back(city);
    this->id ++;


}