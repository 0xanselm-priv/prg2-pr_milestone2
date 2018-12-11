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

float Iterator::inpact(int i, int a, VertexController& vertex_controller, CityController& city_controller) {
    float city_x = city_controller.get_city(i).get_x();
    float city_y = city_controller.get_city(i).get_y();

    float vertex_x = vertex_controller.get_vertex(a).get_x();
    float vertex_y = vertex_controller.get_vertex(a).get_y();

    float t_n = temperatur(this->n);

    double top = pow(exp(1), -(pow(pow(city_x - vertex_x, 2) + pow(city_y - vertex_y, 2),0.5))/t_n);
    double bottom = 0;

    float vertex_x_a = 0;
    float vertex_y_a = 0;

    for(int c = 0; c < this->m; c++){
        vertex_x_a = vertex_controller.get_vertex(c).get_x();
        vertex_y_a = vertex_controller.get_vertex(c).get_y();
        cout << "Vertex " << c << " = (" << vertex_x_a << "|" << vertex_y_a << ")" << endl;
        bottom += pow(exp(1), -(pow(pow(city_x - vertex_x_a, 2) + pow(city_y - vertex_y_a, 2),0.5))/t_n);
    }

    cout << "INPACT(" << i << "," << a << ") = " << top/bottom << endl << "TOP = " << top << endl << "BOTTOM = " << bottom << endl << "Temperatur: " << t_n << endl << endl;

    return top/bottom;
}

float Iterator::temperatur(int n){
    return 2*pow(temp_curve(n), 2);
} // WRONG not yet working ! Ask TUT.

float Iterator::temp_curve(int m){
    return max(pow(0.99, floor(m/50)) * this->k, 0.01);
}


void Iterator::apply(VertexController& vertex_controller, CityController& city_controller) {
    VertexController old_vertexes = vertex_controller;

    for(int a = 0; a < vertex_controller.get_id(); a++){

        // get number of vertexes
        this->m = vertex_controller.get_id();

        float a_x = vertex_controller.get_vertex(a).get_x();
        float a_y = vertex_controller.get_vertex(a).get_y();

        cout << "Vector " << a << "(" << a_x << ", " << a_y << ")\n\n";

        double alpha_x = 0;
        double alpha_y = 0;

        for(int i = 0; i < city_controller.get_id(); i++){
            float impact = inpact(i, a, old_vertexes, city_controller);
            alpha_x += impact * (city_controller.get_city(i).get_x() - a_x);
            alpha_y += impact * (city_controller.get_city(i).get_y() - a_y);
        }
        cout << "LETS Apply!" << endl;
        double beta_x = old_vertexes.get_vertex((((a-1)%m)+m)%m).get_x() - (2 * a_x) + old_vertexes.get_vertex((a+1)%m).get_x();
        double beta_y = old_vertexes.get_vertex((((a-1)%m)+m)%m).get_y() - (2 * a_y) + old_vertexes.get_vertex((a+1)%m).get_y();

        cout << "BETA X = " << beta_x << "  For Vector " << a << " -  In roound " << n <<  endl;
        cout << "BETA Y = " << beta_y << "  For Vector " << a << " -  In roound " << n <<  endl;

        beta_x *= temp_curve(this->n);
        beta_y *= temp_curve(this->n);

        float ret_x = (this->alpha * alpha_x) + (this->beta * beta_x);
        float ret_y = (this->alpha * alpha_y) + (this->beta * beta_y);

        cout << "Delta for Vector " << a << ": alpha = (" << alpha_x << "|" << alpha_y << "), beta = (" << beta_x << "|" << beta_y << ")" << endl << "K(" << this->n << ") ="<< temp_curve(this->n) << endl;

        vertex_controller.aply_delta(a, ret_x, ret_y);
    }

    this->n++;
}

bool Iterator::check_single_city(VertexController& vertex_controller, City c) {
    for (int a = 0; a < vertex_controller.get_id(); a++) {
        Vertex v = vertex_controller.get_vertex(a);
        if(c%v < this->eta_goal){
            return true;
        }
    }
    return false;
}

bool Iterator::check_distance(VertexController& vertex_controller, CityController& city_controller){
    for(int i = 0; i < city_controller.get_id(); i++){
        City c = city_controller.get_city(i);
        if (!check_single_city(vertex_controller, c)){
            return true;
        }
    }
    return false;
}



void Iterator::solve(VertexController& vertex_controller, CityController& city_controller){
    while(this->n < this->iter_max && check_distance(vertex_controller, city_controller)) {
        apply(vertex_controller, city_controller);
    }
    cout << "One of the criterias where reached..." << endl;
}

