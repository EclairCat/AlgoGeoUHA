//
// Created by rabie on 05/11/2021.
//

#include "graphics.h"
#include "Classes/point.h"
#include "Classes/polygone.h"
#include "Classes/enveloppe.h"
#include "iostream"
#include <vector>

void segment(const Point &a, const Point &b){
    line(a.x(), a.y(), b.x(), b.y());
}

void trace(const Polygone &P){

    Sommet *cursor = P.premier();
    segment(cursor->coordonnees(), cursor -> suivant()->coordonnees());

    cursor = cursor->suivant();

    std::cout << "Sommet Prem : " << std::endl;
    std::cout << P.premier()->coordonnees().x() << std::endl;
    std::cout << P.premier()->coordonnees().y() << std::endl;

    while(cursor != P.premier()){
        std::cout << "Sommet : " << std::endl;
        std::cout << cursor->coordonnees().x() << std::endl;
        std::cout << cursor->coordonnees().y() << std::endl;
        segment(cursor->coordonnees(), cursor -> suivant()->coordonnees());
        cursor = cursor ->suivant();
    }

    std::cout <<  "Tracing DONE!" << std::endl;


}


int main()
{
    //Initialisation graph
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);

    vector<Point> *tab_point = new vector<Point>();
    Point *point1 = new Point(100,330);
    Point *point2 = new Point(340,400);
    Point *point3 = new Point(200,160);
    Point *point4 = new Point(350,300);
    Point *point5 = new Point(180,220);
    Point *point6 = new Point(500,300);

    tab_point->push_back(*point1);
    tab_point->push_back(*point2);
    tab_point->push_back(*point3);
    tab_point->push_back(*point4);
    /*tab_point->push_back(*point5);
    tab_point->push_back(*point6);*/

    Polygone *p = new Polygone();
    enveloppe(*tab_point, *p);

    /*
    Sommet *sommet1 = p->ajouteSommet(*point1);

    Sommet *sommet2 = p->ajouteSommet(*point2, sommet1);
    Sommet *sommet3 = p->ajouteSommet(*point3, sommet2);
    Sommet *sommet4 = p->ajouteSommet(*point4, sommet3);
    Sommet *sommet5 = p->ajouteSommet(*point5, sommet4);
    Sommet *sommet6 = p->ajouteSommet(*point6, sommet5);
    trace(*p);
     */


    delay(50000);
    closegraph();


    return 0;
}

// compilation => g++ affichage.cpp -o demo -lgraph