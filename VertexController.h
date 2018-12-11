//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H
#define PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H

#include "CityController.h"
#include <vector>
#include "Vertex.h"
using namespace std;


class VertexController {
private:
    vector <Vertex> vertices;
    int id = 0;
    float cv_ratio;
    float radius;
    int city_num;
    int vertex_num;
    float mid_x = 0;
    float mid_y = 0;

public:
    VertexController(float cv_ratio, float radius, CityController cities); // k is the number of cities

    Vertex get_vertex(int id);
    vector <Vertex> get_vertices(){
        return this->vertices;
    };
    int get_id(){
        return this->id;
    }

    void aply_delta(int id, float delta_x, float delta_y){
        this->vertices[id].set_x(vertices[id].get_x() + delta_x);
        this->vertices[id].set_y(vertices[id].get_y() + delta_y);
    }
};


#endif //PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H
