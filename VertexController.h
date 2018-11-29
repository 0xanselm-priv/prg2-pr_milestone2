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
    void aply_delta(int id, vector <float> delta){
        Vertex vertex = this->vertices[id];
        vector <float> new_coords {vertex.get_x() + delta[0], vertex.get_y() + delta[1]};
        vertex.set_coords(new_coords);
    }
    vector <Vertex> get_vertices();
    int get_id(){
        return this->id;
    }
};


#endif //PRG2_PR_MILESTONE2_VERTEXCONTROLLER_H
