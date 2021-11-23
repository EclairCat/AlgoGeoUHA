#include "enveloppe.h"
#include "../affichage.h"
#include "iostream"
#include <algorithm>
Sommet* enveloppe_triple(const Point &a, const Point &b, const Point &c, Polygone &P){

    Sommet* s_a = P.ajouteSommet(a);
    Sommet* s_b = P.ajouteSommet(b, s_a);
    Sommet* s_c = nullptr;
    if(c.aGauche(a,b) == -1){
        s_c = P.ajouteSommet(c, s_b);
    }
    else {
        s_c = P.ajouteSommet(c, s_a);
    }


    return s_c;
};

bool comparePoint(Point i1, Point i2)
{
    return (i1.x() < i2.x());
}

// Construit dans le polygone P l�enveloppe convexe de l'ensemble de points donn� dans T.
// On suppose P initialement vide.
void enveloppe(vector<Point>&T, Polygone &P){

    sort(T.begin(), T.end(), comparePoint);

    Sommet* cursor = enveloppe_triple(T[0],T[1],T[2], P);

    int index = 3;
    Sommet* som_max = cursor;
    while ( index < T.size()){

        cursor = som_max;

        //parcour vers l'avant
        while(T[index].aGauche(cursor->coordonnees(), cursor->suivant()->coordonnees()) == 1){
            cursor = cursor->suivant();
        }
        Sommet* fin = cursor;


        cursor = som_max;
        //parcour vers l'arriere
        while(T[index].aGauche(cursor->coordonnees(), cursor->precedent()->coordonnees()) == -1){
            cursor = cursor->precedent();
        }
        Sommet* debut = cursor;

        cursor = cursor->suivant();
        //Parcour et suppression
        while(cursor != fin){
            cursor = cursor->suivant();
            P.supprimeSommet(cursor->precedent());
        }

        som_max = P.ajouteSommet(T[index],debut);
        index++;
        trace_p(P);
    }

    std::cout <<  "Tracing!" << std::endl;

    trace_p(P);


};