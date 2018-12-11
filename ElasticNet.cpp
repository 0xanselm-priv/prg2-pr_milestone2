//
// Created by Niels Heissel on 27.11.18.
//

#include "ElasticNet.h"
#include "Iterator.h"
#include "VertexController.h"
#include <iostream>
#include <iostream>
using namespace std;


ElasticNet::ElasticNet(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k, float radius) {
    this->cv_ratio = cv_ratio;
    this->eta_goal = eta_goal;
    this->iter_max = iter_max;
    this->alpha = alpha;
    this->beta = beta;
    this->k = k;
    this->radius = radius;
}

ElasticNet::ElasticNet() {
    this->cv_ratio;
    this->eta_goal;
    this->iter_max;
    this->alpha;
    this->beta;
    this->k;
    this->radius;
}


void ElasticNet::add_city(float x, float y) {
    this->city_num ++;
    city_controller.add_city(x, y);

    VertexController ver {this->cv_ratio, this->radius, city_controller};
    this->vertex_controller = ver;

    this->mid_x = vertex_controller.get_mid_x();
    this->mid_y = vertex_controller.get_mid_y();

}

void ElasticNet::solve() {
    Iterator it {this->eta_goal, this->iter_max, this->alpha, this->beta, this->k};
    cout << "SOLVING ... " << endl;

    it.solve(this->vertex_controller, this->city_controller);
}


void ElasticNet::print_city() {
    for(int i = 0; i < city_controller.get_id(); i++){
        cout << i << ": (" << city_controller.get_city(i).get_x() << ", " <<  city_controller.get_city(i).get_y() << ") " << endl;
    }
}

void ElasticNet::set_cv_ratio(float cv_ratio){
    this->cv_ratio = cv_ratio;
}

void ElasticNet::set_eta_goal(float eta_goal){
    this->eta_goal = eta_goal;
}

void ElasticNet::set_iter_max(int iter_max){
    this->iter_max = iter_max;
}

void ElasticNet::set_alpha(float alpha){
    this->alpha = alpha;
}

void ElasticNet::set_beta(float beta){
    this->beta = beta;
}

void ElasticNet::set_k(float k) {
    this->k = k;
}

void ElasticNet::set_radius(float radius){
    this->radius = radius;
}

void ElasticNet::print_vertex() {
    for(int i = 0; i < vertex_controller.get_id(); i++){
        cout << i << ": (" << vertex_controller.get_vertex(i).get_x() << ", " <<  vertex_controller.get_vertex(i).get_y() << ") " << endl;
    }
}
