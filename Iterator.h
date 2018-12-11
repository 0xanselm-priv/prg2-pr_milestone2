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
    int n = 0;
    int m = 0;
public:
    Iterator(float, int, float, float, float);

    vector <float> add(vector <float>, vector <float>);
    vector <float> sub(vector <float>, vector <float>);

    void apply(VertexController&, CityController&);

    void Solve(VertexController&, CityController&); // look up, adding two vectors

    bool check_single_city(VertexController& vertex_controller, City c);
    bool check_distance(VertexController& vertex_controller, CityController& city_controller);
    float temp_curve(int);
    float temperatur(int);
    float inpact(int i, int a, VertexController& vertex_controller, CityController& city_controller);
};


#endif //PRG2_PR_MILESTONE2_ITERATOR_H
