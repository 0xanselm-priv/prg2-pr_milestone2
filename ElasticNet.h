//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_ELASTICNET_H
#define PRG2_PR_MILESTONE2_ELASTICNET_H

#include "VertexController.h"
#include "CityController.h"
#include "City.h"
#include "Iterator.h"
#include <vector>

class ElasticNet {
 public:
  ElasticNet(float cv_ratio, float eta_goal, int iter_max, float alpha, float beta, float k);
  void AddCity(float x, float y); // initalisiert jedes mal ein neues vretex controller und ersetzt dieses
 
 private:
  float cv_ratio;
  float eta_goal;
  int iter_max;
  float alpha;
  float beta;
  float k;
  int city_num = 0;
  VertexController vertex_controller {0};
  CityController city_controller;
};

#endif //PRG2_PR_MILESTONE2_ELASTICNET_H
