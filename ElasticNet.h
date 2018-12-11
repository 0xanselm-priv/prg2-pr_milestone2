//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_ELASTICNET_H
#define PRG2_PR_MILESTONE2_ELASTICNET_H

#include "VertexController.h"
#include "CityController.h"
#include "City.h"
#include "Vertex.h"
#include "Iterator.h"
#include <vector>
using namespace std;


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
    ElasticNet();

    void AddCity(float x, float y); // initalisiert jedes mal ein neues vretex controller und ersetzt dieses
    void Solve();
    void PrintVertex();
    void PrintCity();

    float mid_x(){ return this->mid_x; }
    float mid_y(){ return this->mid_y; }
    vector <Vertex> vertex_list(){ return this->vertex_controller.get_vertices(); }
    vector <City> city_list(){ return this->city_controller.get_cities(); }
    float cv_ratio(){ return this->cv_ratio; }
    float eta_goal(){ return this->eta_goal; }
    int iter_max(){ return this->iter_max; }
    float alpha(){ return this->alpha; }
    float beta(){ return this->beta; }
    float k(){ return this->k; }
    float radius(){ return this->radius; }

    void set_cv_ratio(float cv_ratio) { this->cv_ratio = cv_ratio; }
    void set_eta_goal(float eta_goal) { this->eta_goal = eta_goal; }
    void set_iter_max(int iter_max) { this->iter_max = iter_max; }
    void set_alpha(float alpha) { this->alpha = alpha; }
    void set_beta(float beta) { this->beta = beta; }
    void set_k(float k) { this->k = k; }
    void set_radius(float radius) { this->radius = radius; }
};


#endif //PRG2_PR_MILESTONE2_ELASTICNET_H
