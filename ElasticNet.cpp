//
// Created by Niels Heissel on 27.11.18.
//

#include "ElasticNet.h"
#include "Iterator.h"
#include <iostream>
#include <iostream>
using namespace std;


ElasticNet::ElasticNet(float cv_ratio, float eta_goal, int iter_max, 
    float alpha, float beta, float k, float radius) 
    : cv_ratio(cv_ratio), eta_goal(eta_goal), iter_max(iter_max),
    alpha(alpha), beta(beta), k(k), radius(radius) {}

ElasticNet::ElasticNet() {}

void ElasticNet::AddCity(float x, float y) {
    this->city_num ++;
    city_controller.AddCity(x, y);
    VertexController ver { this->cv_ratio, this->radius, city_controller };
    this->vertex_controller = ver;
}

void ElasticNet::Solve() {
    Iterator it {this->eta_goal, this->iter_max, this->alpha, this->beta, this->k};
    cout << "SOLVING ... " << endl;
    it.Solve(this->vertex_controller, this->city_controller);
}

void ElasticNet::PrintCity() {
    for(int i = 0; i < city_controller.get_id(); i++){
        cout << i << ": (" << city_controller.get_city(i).get_x() << ", " <<  city_controller.get_city(i).get_y() << ") " << endl;
    }
}

void ElasticNet::PrintVertex() {
    for(int i = 0; i < vertex_controller.get_id(); i++){
        cout << i << ": (" << vertex_controller.get_vertex(i).get_x() << ", " <<  vertex_controller.get_vertex(i).get_y() << ") " << endl;
    }
}

