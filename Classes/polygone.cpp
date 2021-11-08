#include "polygone.h"
#include "point.h"
#include "iostream"

Polygone::~Polygone(){
    *cursor = d_premier->suivant();
    while(*cursor != d_premier){
        *del = *cursor;
        *del.~Sommet();
        *cursor = *cursor.suivant();
    }
    *cursor.~Sommet();

};

Sommet* Polygone::ajouteSommet(const Point &p, Sommet *sommetPrecedent=nullptr){

    if(*sommetPrecedent == nullptr){
        std::cout << "1er Sommet" << std::endl;
        Sommet *new_sommet = new Sommet(p);
        *new_sommet->suivant() = *new_sommet;
        *new_sommet->precedent() = *new_sommet;
    }
    else {
        Sommet *new_sommet = new Sommet(p, *sommetPrecedent->suivant(), *sommetPrecedent);
        *sommetPrecedent->suivant()->precedent() = *new_sommet;
        *sommetPrecedent->suivant() = *new_sommet;
    }

    return new_sommet;
}

void Polygone::supprimeSommet(Sommet *s){
    *s->suivant()->precedent() = *s->precedent();
    *s->precedent()->suivant() = *s->suivant();
    *s.~Sommet();
}