#include "point.h"
#include "stdlib.h"
#include "iostream"


int Point::aGauche(const Point &a, const Point &b) const{

    int determinant = abs(b.x()-a.x()) * abs(d_y - a.y()) - abs(d_x - a.x()) * abs(b.y() - a.y());
    int res = 0;
    if(determinant < 0){
        std::cout << "A Droite!" << std::endl;
        res = -1;
    }
    else {
        std::cout << "A Gauche!" << std::endl;
        res = 1;
    }

    return res;


}