//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_CITYCONTROLLER_H
#define PRG2_PR_MILESTONE2_CITYCONTROLLER_H

#include "City.h"
#include <vector>
using namespace std;

class CityController {
 public:
  CityController();
  int id() { return this->id_; }
  City city(int id){ return cities_[id]; }
  void AddCity(float x, float y); // increment id every call ----- look for minimalabstand
  vector <City> get_cities() { return cities_; }
 private:
  vector <City> cities_;
  int id_;
};


#endif //PRG2_PR_MILESTONE2_CITYCONTROLLER_H
