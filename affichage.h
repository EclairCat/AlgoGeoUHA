#ifndef AFFICHAGE_H
#define AFFICHAGE_H


#include "Classes/point.h"
#include "Classes/polygone.h"


// trace un segment entre deux points a et b
void segment(const Point & a, const Point & b);

// trace le polygone P dans une fen�tre graphique
void trace(const Polygone &P);

#endif
