//
// Created by Niels Heissel on 27.11.18.
//
#include <iostream>
#include "ElasticNet.h"

using namespace std;

int main(){
    cout << "Hello World" << endl;

    ElasticNet net {2, 0.003, 200, 1, 0.01, 0.1, 1}; //(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k, float radius);

    net.PrintVertex();
    net.PrintCity();

    net.AddCity(0.0, 2);
    net.AddCity(0.0, -2);


    net.PrintVertex();
    net.PrintCity();

    net.Solve();

    net.PrintVertex();
    net.PrintCity();
}

