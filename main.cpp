//
// Created by Niels Heissel on 27.11.18.
//
#include <iostream>
#include "ElasticNet.h"

using namespace std;

int main(){
    cout << "Hello World" << endl;

    ElasticNet net {2, 0.005, 100, 1, 1, 0.1, 0.5}; //(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k, float radius);

    net.print_vertex();
    net.print_city();

    net.add_city(0.0, 0.5);
    net.add_city(0.0, -0.5);


    net.print_vertex();
    net.print_city();

    net.solve();

    net.print_vertex();
    net.print_city();
}

