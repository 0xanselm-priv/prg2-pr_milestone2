//
// Created by Niels Heissel on 27.11.18.
//

#ifndef PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H
#define PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H

#include <vector>
#include "Vertex.h"
using namespace std;


class VertexController {
private:
    vector <Vertex> vertices;
    int id;
public:
    VertexController(int k); // k is the number of cities
    Vertex get_vertex(int id);
    void aply_delta(int id, int delta){
        this->vertices[id].set_x(delta);
    }
    vector <Vertex> get_vertices();
};


#endif //PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H
