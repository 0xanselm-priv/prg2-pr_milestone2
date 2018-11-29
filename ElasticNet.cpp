//
// Created by Niels Heissel on 27.11.18.
//

#include "ElasticNet.h"


ElasticNet::ElasticNet(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k) {
    this->cv_ratio = cv_ratio;
    this->eta_goal = eta_goal;
    this->iter_max = iter_max;
    this->alpha = alpha;
    this->beta = beta;
    this->k = k;
}

void ElasticNet::add_city(float x, float y) {
    this->city_num ++;
    city_controller.add_city(x, y);

    VertexController ver {this->city_num};
    this->vertex_controller = ver;
}