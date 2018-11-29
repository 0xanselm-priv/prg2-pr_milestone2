//
// Created by Niels Heissel on 27.11.18.
//

#include "Iterator.h"
#include <vector>
#include <iostream>
using namespace std;



Iterator::Iterator(float eta_goal, int iter_max){
    this->eta_goal = eta_goal;
    this->iter_max = iter_max;
};

vector <float> Iterator::add(vector<float> x, vector<float> y) {
    vector <float> ret_vector {x[0] + y[0], x[1] + y[1]};
    return ret_vector;
}
vector <float> Iterator::sub(vector<float> x, vector<float> y) {
    vector <float> ret_vector {x[0] - y[0], x[1] - y[1]};
    return ret_vector;
}

void Iterator::apply(VertexController vertex_controller, CityController city_controller){

    VertexController old_vertexes = vertex_controller; // saves vertex of n because calcula


    for(int a = 0; a < vertex_controller.get_id(); a++){
        vector <float> delta {2.123, 21.21}; // calc delta here ? use old vertex for calculations and change in vertex_controller

        // first part of equation up to beta
        vector <float> alpha_vector {0, 0};
        for(int i = 0; i < city_controller.get_id(); i++){
            add(alpha_vector, v(i, a) * sub(city_controller.get_city(i).get_coords(), old_vertexes.get_vertex(a).get_coords())) // V is yet to be implemented
        }

        // K(n) and M are yet to be implemented
        vector <float> beta_vector {K(n) * (sub(add(old_vertexes.get_vertex(a-1 % M).get_coords(), old_vertexes.get_vertex(a).get_coords()), 2* old_vertexes.get_vertex(a+1%M).get_coords()));



        delta = add(alpha_vector, beta_vector);

        vertex_controller.aply_delta(a, delta); // calculates n
    }



}

VertexController Iterator::solve(VertexController vertex_controller, CityController city_controller){
    int iter_number = 0;
    while(true){
        apply(vertex_controller, city_controller);
        cout << "Ha" << endl;
        break;
    }
}