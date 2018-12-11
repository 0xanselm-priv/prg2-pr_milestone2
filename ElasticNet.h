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


public:

    CityController city_controller;
    VertexController vertex_controller {0, 0, city_controller};

    ElasticNet(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k, float radius);
    ElasticNet();

    void add_city(float x, float y); // initalisiert jedes mal ein neues vretex controller und ersetzt dieses
    void solve();
    void aply();

    void print_vertex();
    void print_city();

    float get_mid_x(){
        return this->mid_x;
    }
    float get_mid_y(){
        return this->mid_y;
    }

    vector <Vertex> get_vertex_list(){
        return this->vertex_controller.get_vertices();
    }
    vector <City> get_city_list(){
        return this->city_controller.get_cities();
    }

    float get_cv_ratio(){
        return this->cv_ratio;
    }
    float get_eta_goal(){
        return this->eta_goal;
    }
    int get_iter_max(){
        return this->iter_max;
    }
    float get_alpha(){
        return this->alpha;
    }
    float get_beta(){
        return this->beta;
    }
    float get_k(){
        return this->k;
    }
    float get_radius(){
        return this->radius;
    }

    void set_cv_ratio(float cv_ratio);
    void set_eta_goal(float eta_goal);
    void set_iter_max(int iter_max);
    void set_alpha(float alpha);
    void set_beta(float beta);
    void set_k(float k);
    void set_radius(float radius);
};


#endif //PRG2_PR_MILESTONE2_ELASTICNET_H
