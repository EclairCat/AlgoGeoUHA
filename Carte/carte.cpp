//
// Created by rabie on 10/11/2021.
//

#include "carte.h"

DemiCote* Carte::ajouteDemiCote(DemiCote* precedent, DemiCote* oppose){

    DemiCote *n_dm = new DemiCote(precedent->suivant(),
                                  precedent,
                                  oppose,
                                  precedent->d_sommet,
                                  d_tabDemiCote.size()
                                  );

    precedent->suivant()->d_precedent = n_dm;
    precedent->d_suivant = n_dm;

    if(oppose){
        oppose->d_oppose = n_dm;
    }

    d_tabDemiCote.push_back(n_dm);

    return n_dm;
};

DemiCote* Carte::ajouteDemiCote(const Point &p, DemiCote* oppose){

    DemiCote *n_dm = new DemiCote(nullptr,
                                  nullptr,
                                  oppose,
                                  new SommetC(p),
                                  d_tabDemiCote.size()
    );
    n_dm->d_suivant = n_dm;
    n_dm->d_precedent = n_dm;
    d_tabDemiCote.push_back(n_dm);
    if(oppose){
        oppose->d_oppose = n_dm;
    }

    return n_dm;

};



// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2 dont
// precedent1 et precedent2 seront les demi-c�t�s pr�c�dents respectifs.
// precedent1 et precedent2 doivent �tre effectivement pr�sents dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(DemiCote* precedent1, DemiCote* precedent2){
    DemiCote *dc1 = ajouteDemiCote(precedent1);
    DemiCote *dc2 = ajouteDemiCote(precedent2, dc1);
    dc1->d_oppose = dc2;

    return dc1;

};

// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
// precedent1 sera le demi-c�t� pr�c�dent de dc1. dc2 sera issu d�un
// nouveau sommet (� cr�er) dont les coordonn�es sont celles du point p2.
// precedent1 doit �tre effectivement pr�sent dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(DemiCote* precedent1, const Point& p2){

    DemiCote *dc1 = ajouteDemiCote(precedent1);
    DemiCote *dc2 = ajouteDemiCote(p2, dc1);
    dc1->d_oppose = dc2;

    return dc1;


};

// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
// precedent2 sera le demi-c�t� pr�c�dent de dc2. dc1 sera issu d�un
// nouveau sommet (� cr�er) dont les coordonn�es sont celles du point p1.
// precedent2 doit �tre effectivement pr�sent dans la carte.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(const Point& p1, DemiCote* precedent2){
    DemiCote *dc1 = ajouteDemiCote(p1);
    DemiCote *dc2 = ajouteDemiCote(precedent2, dc1);
    dc1->d_oppose = dc2;

    return dc1;
};

// Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
// dc1 et dc2 seront issus de deux nouveaux sommets (� cr�er) dont les coordonn�es
// sont celles des points p1 et p2 respectivement.
// Renvoie l'adresse de dc1.
DemiCote* Carte::ajouteCote(const Point& p1, const Point& p2){

    DemiCote* dc1 = ajouteDemiCote(p1);
    DemiCote* dc2 = ajouteDemiCote(p2, dc1);
    dc1->d_oppose= dc2;

    return dc1;

};

Carte::~Carte(){

    for ( DemiCote *dm : d_tabDemiCote){
        delete dm->d_sommet;
        delete dm;
    }

};