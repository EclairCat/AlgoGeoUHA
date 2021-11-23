//
// Created by RabiePC on 22/11/2021.
//

#ifndef GEOALGO_TRIANGULATION_H
#define GEOALGO_TRIANGULATION_H

#include "../Classes/point.h"
#include "carte.h"
#include <vector>

using namespace std;

// Construit dans le polygone P l�enveloppe convexe de l'ensemble de points donn� dans T.
// On suppose P initialement vide.
void triangulation(vector<Point>&T, Carte &C);

DemiCote* enveloppe_triple(const Point &a, const Point &b, const Point &c, Carte &C);




#endif //GEOALGO_TRIANGULATION_H
