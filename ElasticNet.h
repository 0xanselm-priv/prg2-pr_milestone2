//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_ELASTICNET_H
#define PRG2_PR_MILESTONE2_ELASTICNET_H

#include "VertexController.h"
#include "CityController.h"
#include "City.h"
#include "Iterator.h"
#include <vector>

class ElasticNet {
private:
    float cv_ratio;
    float eta_goal;
    int iter_max;

    VertexController vertex_controller {0};
    CityController city_controller;
public:
    ElasticNet(float cv_ratio, float eta_goal, int iter_max);
    void add_city(int x, int y); // initalisiert jedes mal ein neues vretex controller und ersetzt dieses

    void start(){
        this->vertex_controller = Iterator(this->eta_goal, this->iter_max).solve(this->vertex_controller, this->city_controller);  // start übergibt iterator all die Objekte, die Iterator dann verändert und aktualisiert das elatische netz mit dem ergbenis
    };

};


#endif //PRG2_PR_MILESTONE2_ELASTICNET_H
