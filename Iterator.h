//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_ITERATOR_H
#define PRG2_PR_MILESTONE2_ITERATOR_H

#include <vector>
#include "Iterable.h"
#include "VertexController.h"
#include "CityController.h"
using namespace std;

class Iterator: public Iterable {
private:
    float eta_goal;
    int iter_max;
    float alpha;
    float beta;
    float k;
    int n;
public:
    Iterator(float, int);
    vector <float> add(vector <float>, vector <float>);
    vector <float> sub(vector <float>, vector <float>);
    void apply(VertexController &, CityController &);
    VertexController solve(VertexController &, CityController &); // look up, adding two vectors

    float temp_curve(int);
    float temperatur(int);
    float inpact(int i, int a, vector <Vertex> verticis, vector <City> cities);
};


#endif //PRG2_PR_MILESTONE2_ITERATOR_H
