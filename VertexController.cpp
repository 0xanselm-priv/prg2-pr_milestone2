//
// Created by Niels Heissel on 27.11.18.
//

#include "CityController.h"
#include "VertexController.h"
#include "Vertex.h"
#include "math.h"
#include <vector>
using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105820974944592

VertexController::VertexController(float cv_ratio, float radius, CityController cities) {
    this->cv_ratio = cv_ratio;
    this->city_num = cities.get_id();
    this->radius = radius;
    this->vertex_num = ceil(city_num*cv_ratio);

    if(city_num != 0) {
        float degree = 360 / vertex_num;


        for (int i = 0; i < this->city_num; i++) {
            mid_x += cities.get_city(i).get_x();
            mid_y += cities.get_city(i).get_y();
        }
        this->mid_x = mid_x / city_num;
        this->mid_y = mid_y / city_num;

        cout << "MIDLE POINT: " << mid_x << ", " << mid_y << endl;

        for (int k = 0; k < this->vertex_num; k++) {
            float param = degree * k;
            float x = (this->mid_x + cos(param * PI / 180.0) * this->radius);
            float y = (this->mid_y + sin(param * PI / 180.0) * this->radius);
            int x_r = x * 10000;
            int y_r = y * 10000;
            x = x_r/10000.0;
            y = y_r/10000.0;
            Vertex vertex{x, y, id};
            this->vertices.push_back(vertex);
            this->id++;
        }
    }

}

Vertex VertexController::get_vertex(int id){
    return this->vertices[id];
}

