//
// Created by Niels Heissel on 27.11.18.
//



#ifndef PRG2_PR_MILESTONE2_CITY_H
#define PRG2_PR_MILESTONE2_CITY_H

using namespace std;



class City {
private:
    int x;
    int y;
    int id;
public:
    City(int x, int y, int id);
    int get_x();
    int get_y();
    int get_id();
    void set_x(int x);
    void set_y(int y);
    void set_id(int id);
};


#endif //PRG2_PR_MILESTONE2_CITY_H
