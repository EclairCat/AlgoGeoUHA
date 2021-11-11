//
// Created by rabie on 05/11/2021.
//

#include "graphics.h"
#include "Classes/point.h"
//#include "Classes/polygone.h"
//#include "Classes/enveloppe.h"
#include "iostream"
#include "Carte/carte.h"
#include <vector>

void segment(const Point &a, const Point &b){
    line(a.x(), a.y(), b.x(), b.y());
}

/*
void trace_p(const Polygone &P){

    Sommet *cursor = P.premier();
    segment(cursor->coordonnees(), cursor -> suivant()->coordonnees());

    outtextxy(cursor->coordonnees().x(), cursor->coordonnees().y()+10, "1");


    cursor = cursor->suivant();

    std::cout << "Sommet Prem : " << std::endl;
    std::cout << P.premier()->coordonnees().x() << std::endl;
    std::cout << P.premier()->coordonnees().y() << std::endl;
    delay(1000);

    int num = 2;
    while(cursor != P.premier()){
        std::cout << "Sommet : " << std::endl;
        std::cout << cursor->coordonnees().x() << std::endl;
        std::cout << cursor->coordonnees().y() << std::endl;
        segment(cursor->coordonnees(), cursor -> suivant()->coordonnees());

        outtextxy(cursor->coordonnees().x() -10, cursor->coordonnees().y()+10, const_cast<char*>(to_string(num).c_str()));

        cursor = cursor ->suivant();
        num++;
        delay(1000);
    }

    std::cout <<  "Tracing DONE!" << std::endl;


}
*/

void trace_c(const Carte &C){

    std::cout <<  "Tracing Carte!" << std::endl;

    int num = 0;
    while(num < C.nbDemiCote()){
        DemiCote *dm = C.demiCote(num);
        segment(dm->coordonnees(), dm->oppose()->coordonnees());
        num++;
    }

}


int main()
{
    //Initialisation graph
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);

    Point *point1 = new Point(100,330);
    Point *point2 = new Point(340,400);
    Point *point3 = new Point(200,160);
    Point *point4 = new Point(350,300);
    Point *point5 = new Point(180,220);
    Point *point6 = new Point(500,300);


    //Exempel Polygon
    /*
    vector<Point> *tab_point = new vector<Point>();


    tab_point->push_back(*point1);
    tab_point->push_back(*point2);
    tab_point->push_back(*point3);
    tab_point->push_back(*point4);
    tab_point->push_back(*point5);
    tab_point->push_back(*point6);

    Polygone *p = new Polygone();
    //enveloppe(*tab_point, *p);


    Sommet *sommet1 = p->ajouteSommet(*point1);

    Sommet *sommet2 = p->ajouteSommet(*point2, sommet1);
    Sommet *sommet3 = p->ajouteSommet(*point3, sommet2);
    Sommet *sommet4 = p->ajouteSommet(*point4, sommet3);
    Sommet *sommet5 = p->ajouteSommet(*point5, sommet4);
    Sommet *sommet6 = p->ajouteSommet(*point6, sommet5);
    trace(*p);
     */

    //Exemple Carte

    Carte * c = new Carte();

    *c->ajouteCote(*point1,*point2);
    *c->ajouteCote(*point2, *point3);
    *c->ajouteCote(*point1, *point3);

    trace_c(*c);




    delay(50000);
    closegraph();


    return 0;
}

// compilation => g++ affichage.cpp -o demo -lgraph