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
    void add_city(int x, int y); // increment id every call ----- look for minimalabstand
    vector <City> get_cities();
};


#endif //PRG2_PR_MILESTONE2_CITYCONTROLLER_H
