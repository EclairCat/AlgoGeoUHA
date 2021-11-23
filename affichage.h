#ifndef AFFICHAGE_H
#define AFFICHAGE_H


#include "Classes/point.h"
#include "Classes/polygone.h"
#include "Carte/carte.h"


// trace un segment entre deux points a et b
void segment(const Point & a, const Point & b);

void affiche_points(vector<Point>&T);

// trace le polygone P dans une fen�tre graphique
void trace_p(const Polygone &P);

void trace_c(const Carte &C);

#endif
