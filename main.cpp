//
// Created by Niels Heissel on 27.11.18.
//
#include <iostream>
#include "ElasticNet.h"

using namespace std;

int main(){
    cout << "Hello World" << endl;

    ElasticNet net {2, 0.003, 200, 1, 0.01, 0.1, 1}; //(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k, float radius);

    net.print_vertex();
    net.print_city();

    net.add_city(0.0, 2);
    net.add_city(0.0, -2);


    net.print_vertex();
    net.print_city();

    net.solve();

    net.print_vertex();
    net.print_city();
}

