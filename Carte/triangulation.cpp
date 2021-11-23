//
// Created by RabiePC on 22/11/2021.
//

#include "triangulation.h"
#include "../affichage.h"
#include "iostream"
#include "../graphic/graphics.h"
#include <algorithm>


bool comparePointC(Point i1, Point i2)
{
    if(i1.x() == i2.x()){
        return (i1.y() < i2.y());
    }
    else{
        return (i1.x() < i2.x());
    }
}

void triangulation(vector<Point>&T, Carte &C){

    sort(T.begin(), T.end(), comparePointC);

    DemiCote* cursor = C.ajouteCote(T[1], T[0]);

    int index = 2;
    DemiCote* dm_max = cursor;


    while ( index < T.size()){

        cursor = dm_max;

        DemiCote* dm_T = C.ajouteCote(T[index],dm_max->precedent());


        //parcour vers bas
        while(T[index].aGauche(cursor->coordonnees(), cursor->oppose()->coordonnees()) == -1){
            cursor = cursor->oppose()->suivant();
            C.ajouteCote(dm_T, cursor->precedent());
        }

        cursor = dm_max->precedent()->precedent();
        //parcour vers HAUT
        while(T[index].aGauche(cursor->coordonnees(), cursor->oppose()->coordonnees()) == 1){
            cursor = cursor->oppose()->precedent();
            dm_T = C.ajouteCote(dm_T, cursor);
        }
        dm_max = dm_T->suivant();

        index++;

        trace_c(C);
        affiche_points(T);
        //getch();
    }





};