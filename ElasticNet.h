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
    float alpha;
    float beta;
    float k;
    int city_num = 0;
    float radius;

    float mid_x = 0;
    float mid_y = 0;


    CityController city_controller;
    VertexController vertex_controller {0, 0, city_controller};


public:

    ElasticNet(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k, float radius);

    void add_city(float x, float y); // initalisiert jedes mal ein neues vretex controller und ersetzt dieses
    void solve();

    void print_vertex();
    void print_city();

    float get_mid_x(){
        return this->mid_x;
    }

    float get_mid_y(){
        return this->mid_y;
    }


};


#endif //PRG2_PR_MILESTONE2_ELASTICNET_H
