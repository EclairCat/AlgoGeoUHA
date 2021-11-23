//
// Created by rabie on 05/11/2021.
//

#include "graphic//graphics.h"
#include "Classes/point.h"
#include "Classes/polygone.h"
#include "Classes/enveloppe.h"
#include "Carte/triangulation.h"
#include "iostream"
#include "Carte/carte.h"
#include <vector>

int hauteur_fenettre = 1000;
int nb_p = 20;

void segment(const Point &a, const Point &b){
    line(a.x(), hauteur_fenettre- a.y(), b.x(), hauteur_fenettre - b.y());
}

void affiche_point(const Point& a,  char text) {
    circle(a.x(), hauteur_fenettre- a.y(), 3);
    char* t = &text;
    outtextxy(a.x(), hauteur_fenettre- a.y() + 10, t);
}

Point* create_point(){
    int x = rand() % 800 + 100;
    int y = rand() % 800 + 100;
    Point* p = new Point(x,y);
    return p;
}

void affiche_points(vector<Point>&T) {
    int index = 0;
    char text = '1';
    while ( index < T.size()){
        circle(T[index].x(), hauteur_fenettre- T[index].y(), 3);
        char* t = &text;
        outtextxy(T[index].x(), hauteur_fenettre- T[index].y() + 10, t);
        index++;
        text = (int)text + 1;
    }

}


void trace_p(const Polygone &P){

    Sommet *cursor = P.premier();
    segment(cursor->coordonnees(), cursor -> suivant()->coordonnees());

   


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

        cursor = cursor ->suivant();
        num++;
        delay(1000);
    }

    std::cout <<  "Tracing DONE!" << std::endl;


}


void trace_c(const Carte &C){

    cleardevice();

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
    //Initialisation de la fenêtre

    opengraphsize(1500,hauteur_fenettre);

    //Créations des points

    Point *point1 = new Point(100,330);
    Point *point2 = new Point(200,400);
    Point *point9 = new Point(200,500);
    Point *point3 = new Point(300,160);
    Point *point4 = new Point(400,300);
    Point *point5 = new Point(500,220);
    Point *point6 = new Point(600,300);
    Point* point7 = new Point(700, 500);
    Point* point8 = new Point(800, 250);

    vector<Point> *tab_point = new vector<Point>();
    /*
    tab_point->push_back(*point1);
    tab_point->push_back(*point2);
    tab_point->push_back(*point3);
    tab_point->push_back(*point4);
    tab_point->push_back(*point5);
    tab_point->push_back(*point6);
    tab_point->push_back(*point7);
    tab_point->push_back(*point8);
    tab_point->push_back(*point9);
    */

    for(int i =0; i<nb_p; i++){
        Point *point = create_point();
        tab_point->push_back(*point);
    }

    //Exemple Polygon
    /*
    Polygone *p = new Polygone();
    enveloppe(*tab_point, *p);
    delay(10000);
    delete p;
     */


    //Exemple Carte
    Carte * c = new Carte();
    triangulation(*tab_point, *c);
    delete c;

    std::cout <<  "Tracing DONE!" << std::endl;
    getch();
    closegraph();
    return 0;
}

// compilation => g++ affichage.cpp -o demo -lgraph