//
// Created by Niels Heissel on 27.11.18.
//

#include "ElasticNet.h"
#include "Iterator.h"


ElasticNet::ElasticNet(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k, float radius) {
    this->cv_ratio = cv_ratio;
    this->eta_goal = eta_goal;
    this->iter_max = iter_max;
    this->alpha = alpha;
    this->beta = beta;
    this->k = k;
    this->radius = radius;
}

void ElasticNet::add_city(float x, float y) {
    this->city_num ++;
    city_controller.add_city(x, y);

    VertexController ver {this->city_num, this->cv_ratio};
    this->vertex_controller = ver;
}

void ElasticNet::solve() {
    Iterator it {this->eta_goal, this->iter_max, this->alpha, this->beta, this->k};
    it.solve(this->vertex_controller, this->city_controller);
}