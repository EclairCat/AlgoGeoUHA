#include "polygone.h"
#include "point.h"
#include "iostream"

Polygone::~Polygone(){
    Sommet *cursor = d_premier->suivant();

    while(cursor != d_premier){
        Sommet *del = cursor;
        delete del;
        *cursor = *cursor->suivant();
    }
    delete cursor;

};

Sommet* Polygone::ajouteSommet(const Point &p, Sommet *sommetPrecedent){


    Sommet *new_sommet = new Sommet(p);

    if(sommetPrecedent == nullptr){
        std::cout << "1er Sommet" << std::endl;
        new_sommet->d_suivant = new_sommet;
        new_sommet->d_precedent = new_sommet;
        d_premier = new_sommet;
    }
    else {
        std::cout << "Ajout Sommet" << std::endl;
        new_sommet->d_suivant = sommetPrecedent->suivant();
        new_sommet->d_precedent = sommetPrecedent;
        sommetPrecedent->suivant()->d_precedent = new_sommet;
        sommetPrecedent->d_suivant = new_sommet;
    }

    return new_sommet;

};

void Polygone::supprimeSommet(Sommet *s){
    s->suivant()->d_precedent = s->precedent();
    s->precedent()->d_suivant = s->suivant();
    delete s;
};