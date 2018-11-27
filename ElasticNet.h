//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_ELASTICNET_H
#define PRG2_PR_MILESTONE2_ELASTICNET_H

#include "VertexController.h"
#include "CityController.h"

class ElasticNet {
private:
    float cv_ratio;
    VertexController vertex_controller {0};
    CityController city_controller;
public:
    ElasticNet(float cv_ratio);
    void add_city(int x, int y);

};


#endif //PRG2_PR_MILESTONE2_ELASTICNET_H
