#include "point.h"
#include "stdlib.h"
#include "iostream"


int Point::aGauche(const Point &a, const Point &b) const{

    int determinant = ( (b.x()-a.x())  * (d_y - a.y()) ) - ( (d_x - a.x()) * (b.y() - a.y()) ) ;
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