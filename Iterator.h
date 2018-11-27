//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_ITERATOR_H
#define PRG2_PR_MILESTONE2_ITERATOR_H

#include "Iterable.h"
#include "VertexController.h"
#include "CityController.h"

class Iterator: public Iterable {
private:
    float eta_goal;
    int iter_max;
public:
    Iterator(float eta_goal, int iter_max);
    VertexController solve(VertexController, CityController);
};


#endif //PRG2_PR_MILESTONE2_ITERATOR_H
