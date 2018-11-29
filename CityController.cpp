//
// Created by Niels Heissel on 27.11.18.
//

#include "CityController.h"
#include "City.h"

void CityController::AddCity(float x, float y) {
    City city {x, y, this->id_};
    this->cities_.push_back(city);
    this->id_ ++;
}