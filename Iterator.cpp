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



Iterator::Iterator(float eta_goal, int iter_max, float alpha, float beta, float k){
    this->eta_goal = eta_goal;
    this->iter_max = iter_max;
    this->alpha = alpha;
    this->beta = beta;
    this->k = k;
};

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
    float tn = temperatur(this->n);
    for(int m = 0; m < verticis.size(); m++){
        t += pow(exp(1), -((cities[i] % verticis[m])/tn));
        cout << "TEIL " << pow(exp(1), -((cities[i] % verticis[m])/tn)) << endl;
    }
    cout << endl << "V " << i << " tn " << tn << " a " << a << endl << (pow(exp(1), -((cities[i] % verticis[a]) / tn))) / (t) << endl;
    cout << "DER OBERE TEIL " << (pow(exp(1), -((cities[i] % verticis[a]) / tn))) << endl;
    cout << "DER UNTERE TEIL " << t << endl;
    return (pow(exp(1), -((cities[i] % verticis[a]) / tn))) / (t);
}

float Iterator::temperatur(int n){
    return 2*pow(temp_curve(n), 2);
} // WRONG not yet working ! Ask TUT.

float Iterator::temp_curve(int m){
    return max(pow(0.99, floor(m/50)) * this->k, 0.01);
}

void Iterator::apply(VertexController& vertex_controller, CityController& city_controller) {
    cout << "!"  << endl;


    int m = vertex_controller.get_id();
    VertexController old_vertexes = vertex_controller; // saves vertex of n because calcula

    for (int a = 0; a < vertex_controller.get_id(); a++) {
        cout << "VECTOR " << a << endl;
        Vertex alpha_vertex{0, 0, -1};
        Vertex beta_vertex{0, 0, -1};

        // first part of equation (ALPHA)
        for (int i = 0; i < city_controller.get_id(); i++) {
            City city_i = city_controller.get_city(i);
            Vertex vertx_a = old_vertexes.get_vertex(a);
            Vertex rest = ((city_i - vertx_a) * inpact(i, a, vertex_controller.get_vertices(), city_controller.get_cities()));
            cout << "ADASJD " << inpact(i, a, vertex_controller.get_vertices(), city_controller.get_cities()) << endl;
            alpha_vertex = alpha_vertex + rest;
        }

        Vertex alpha_done = (alpha_vertex) * this->alpha;

        cout << alpha_done.get_x() << endl;
        cout << "....." << alpha_done.get_y() << endl;

        Vertex vertex_a_m1 = old_vertexes.get_vertex((a-1) % m);
        Vertex vertex_a_0 = old_vertexes.get_vertex(a);
        int ap = (a+1) % m;
        Vertex vertex_a_p1 = (old_vertexes.get_vertex(ap) * 2);
        Vertex res = (vertex_a_m1 + vertex_a_0) - vertex_a_p1;
        Vertex re = (res * temp_curve(n));
        Vertex beta_done = (beta_vertex + re) * this->beta;

        Vertex delta = alpha_done + beta_done;

        vertex_controller.aply_delta(a, delta);
    }

    this->n++;
}

void Iterator::solve(VertexController& vertex_controller, CityController& city_controller){
    int iter_number = 0;
    while(this->n < this->iter_max) {
        apply(vertex_controller, city_controller);
    }
}