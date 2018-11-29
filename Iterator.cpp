//
// Created by Niels Heissel on 27.11.18.
//

#include "Iterator.h"
#include <vector>
#include <iostream>
#include "City.h"
#include "Vertex.h"
#include <cmath>
using namespace std;



Iterator::Iterator(float eta_goal, int iter_max, float alpha, float beta, float k)
    : eta_goal(eta_goal), iter_max(iter_max), alpha(alpha), beta(beta), k(k) {}

vector <float> Iterator::add(vector<float> x, vector<float> y) {
    vector <float> ret_vector {x[0] + y[0], x[1] + y[1]};
    return ret_vector;
}
vector <float> Iterator::sub(vector<float> x, vector<float> y) {
    vector <float> ret_vector {x[0] - y[0], x[1] - y[1]};
    return ret_vector;
}

float Iterator::inpact(int i, int a, vector <Vertex> verticis, vector <City> cities) {
    float t = 0;
    for(int m = 0; m < verticis.size(); i++){
        t += pow(exp(1), -((cities[i] % verticis[m])/temperatur(this->n)));
    }
    return (pow(exp(1), -((cities[i] % verticis[a]) / temperatur(this->n)))) / (t);
}

float Iterator::temperatur(int n){
    return 2*pow(temp_curve(n), 2);
} // WRONG not yet working ! Ask TUT.

float Iterator::temp_curve(int m){
    return max(pow(0.99, floor(m/50)) * this->k, 0.01);
}

void Iterator::apply(VertexController& vertex_controller, CityController& city_controller) {
    this->n++;
    int m = vertex_controller.id();
    VertexController old_vertexes = vertex_controller; // saves vertex of n because calcula

    for (int a = 0; a < vertex_controller.id(); a++) {
        Vertex alpha_vertex{0, 0, -1};
        Vertex beta_vertex{0, 0, -1};

        // first part of equation (ALPHA)
        for (int i = 0; i < city_controller.id(); i++) {
            City city_i = city_controller.get_city(i);
            Vertex vertx_a = old_vertexes.vertex(a);
            Vertex rest = ((city_i - vertx_a) * inpact(i, a, vertex_controller.get_vertices(), city_controller.get_cities()));
            Vertex alpha_done = (alpha_vertex + rest) * this->alpha;
        }

        Vertex vertex_a_m1 = old_vertexes.vertex(a-1 % m);
        Vertex vertex_a_0 = old_vertexes.vertex(a);
        Vertex vertex_a_p1 = (old_vertexes.vertex(a+1 % m) * 2);
        Vertex res = (vertex_a_m1 + vertex_a_0) - vertex_a_p1;
        Vertex re = (res * temp_curve(n));
        Vertex beta_done = (beta_vertex + re) * this->beta;
    }
}

VertexController Iterator::solve(VertexController& vertex_controller, CityController& city_controller){
    int iter_number = 0;
    while(true){
        apply(vertex_controller, city_controller);
        cout << "Ha" << endl;
        break;
    }

    return vertex_controller;
}