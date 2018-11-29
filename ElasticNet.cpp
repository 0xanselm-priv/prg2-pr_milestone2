//
// Created by Niels Heissel on 27.11.18.
//

#include "ElasticNet.h"


ElasticNet::ElasticNet(float cv_ratio, float eta_goal, 
    int iter_max, float alpha, 
    float beta, float k) : cv_ratio(cv_ratio), eta_goal(eta_goal),
                           iter_max(iter_max), alpha(alpha), beta(beta), k(k) {}
            
void ElasticNet::AddCity(float x, float y) {
    this->city_num++;
    city_controller.AddCity(x, y);
    VertexController ver {this->city_num};
    this->vertex_controller = ver;
}