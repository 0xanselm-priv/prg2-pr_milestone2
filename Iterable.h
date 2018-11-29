//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_ITERABLE_H
#define PRG2_PR_MILESTONE2_ITERABLE_H

#include "VertexController.h"
#include "CityController.h"

class Iterable {
public:
    virtual VertexController apply() = 0;
};

#endif //PRG2_PR_MILESTONE2_ITERABLE_H
