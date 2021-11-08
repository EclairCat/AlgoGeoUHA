//
// Created by rabie on 05/11/2021.
//

#include <graphics.h>
#include "Classes/point.h"
#include "Classes/polygone.h"
#include "iostream"

void segment(const Point &a, const Point &b){
    line(a.x(), a.y(), b.x(), b.y());
}

void trace(const Polygone &P){

    Sommet *cursor = P.premier();

    segment(cursor->coordonnees(), cursor -> suivant()->coordonnees());
    *cursor = *cursor->suivant();

    while(cursor != P.premier()){
        segment(cursor->coordonnees(), cursor -> suivant()->coordonnees());
        *cursor = *cursor ->suivant();
    }


}


int main()
{
    //Initialisation graph
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);

    Point *prem_point = new Point(100,100);
    Point *second_point = new Point(100,200);
    Point *third_point = new Point(200,100);

    Polygone *p = new Polygone();
    Sommet *prem_sommet = p->ajouteSommet(*prem_point);

    std::cout << p->premier()->coordonnees().x() << std::endl;

   /*
    *p->ajouteSommet(*second_point, p->premier());
    trace(*p);

    *p->ajouteSommet(*third_point, p->premier()->suivant());*/


    /*segment(*prem_point, *second_point);
    segment(*second_point, *third_point);
    segment(*prem_point, *third_point);*/

    delay(5000);
    closegraph();
    return 0;
}

// compilation => g++ affichage.cpp -o demo -lgraph