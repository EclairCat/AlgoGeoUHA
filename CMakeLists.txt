# CMakeList.txt : projet CMake pour Algo_Geometrique, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)
project(GeoAlgo)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (GeoAlgo
        affichage.cpp
        affichage.h
        Carte/carte.cpp
        Carte/carte.h
        Carte/triangulation.cpp
        Carte/triangulation.h
        Classes/enveloppe.cpp
        Classes/enveloppe.h
        Classes/point.cpp
        Classes/point.h
        Classes/polygone.cpp
        Classes/polygone.h
        graphic/graphics.h
        graphic/winbgi.cpp)