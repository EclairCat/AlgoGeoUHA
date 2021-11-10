#include "enveloppe.h"
#include "polygone.h"
#include "point.h"
#include "../affichage.h"
#include "iostream"
#include "unistd.h"

Sommet* enveloppe_triple(const Point &a, const Point &b, const Point &c, Polygone &P){

    Sommet* s_a = P.ajouteSommet(a);
    Sommet* s_b = P.ajouteSommet(b, s_a);
    Sommet* s_c = nullptr;
    if(c.aGauche(a,b) == -1){
        s_c = P.ajouteSommet(c, s_a);
    }
    else {
        s_c = P.ajouteSommet(c, s_b);
    }


    return s_c;
};

// Construit dans le polygone P l�enveloppe convexe de l'ensemble de points donn� dans T.
// On suppose P initialement vide.
void enveloppe(vector<Point>&T, Polygone &P){

    Sommet* cursor = enveloppe_triple(T[0],T[1],T[2], P);

    int index = 3;

    while ( index < T.size()){




        Sommet* loop = cursor;

        if(T[index].aGauche(cursor->precedent()->coordonnees(), cursor->coordonnees()) != 1){
            Sommet* t = P.ajouteSommet(T[index], cursor);

            sleep(10);
            index++;
        }
        else{
            *cursor = *cursor->suivant();
        }

        while(cursor != loop){

            if(T[index].aGauche(cursor->precedent()->coordonnees(), cursor->coordonnees()) != 1){
                P.ajouteSommet(T[index], cursor);

                index++;
                break;
            }
            else{
                *cursor = *cursor->suivant();
            }
        }


    }
    std::cout <<  "Tracing!" << std::endl;

    trace(P);


};