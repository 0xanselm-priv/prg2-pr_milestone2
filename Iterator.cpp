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
    float city_y = city_controller.get_city(i).get_x();

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
        bottom += pow(exp(1), -(pow(pow(city_x - vertex_x_a, 2) + pow(city_y - vertex_y_a, 2),0.5))/t_n);
    }

    int ret = (top/bottom) * 10000;

    return ret/10000;
}

float Iterator::temperatur(int n){
    return 2*pow(temp_curve(n), 2);
} // WRONG not yet working ! Ask TUT.

float Iterator::temp_curve(int m){
    return max(pow(0.99, floor(m/50)) * this->k, 0.01);
}


void Iterator::apply(VertexController& vertex_controller, CityController& city_controller) {
    for(int a = 0; a < vertex_controller.get_id(); a++){

        // get number of vertexes
        this->m = vertex_controller.get_id();

        float a_x = vertex_controller.get_vertex(a).get_x();
        float a_y = vertex_controller.get_vertex(a).get_y();

        cout << "Vector " << a << "(" << a_x << ", " << a_y << ")\n\n";

        double alpha_x = 0;
        double alpha_y = 0;

        for(int i = 0; i < city_controller.get_id(); i++){
            float impact = inpact(i, a, vertex_controller, city_controller);
            alpha_x += impact * (city_controller.get_city(i).get_x() - a_x);
            alpha_y += impact * (city_controller.get_city(i).get_y() - a_y);
        }
        cout << "LETS Aply!" << endl;
        double beta_x = vertex_controller.get_vertex((((a-1)%m)+m)%m).get_x() - (2 * a_x) + vertex_controller.get_vertex((a+1)%m).get_x();
        double beta_y = vertex_controller.get_vertex((((a-1)%m)+m)%m).get_y() - (2 * a_y) + vertex_controller.get_vertex((a+1)%m).get_y();

        beta_x *= temperatur(this->n);
        beta_y *= temperatur(this->n);

        float ret_x = (this->alpha * alpha_x) + (this->beta * beta_x);
        float ret_y = (this->alpha * alpha_y) + (this->beta * beta_y);

        vertex_controller.aply_delta(a, ret_x, ret_y);
    }

    this->n++;
}

void Iterator::solve(VertexController& vertex_controller, CityController& city_controller){
    while(this->n < this->iter_max) {
        apply(vertex_controller, city_controller);
    }
}