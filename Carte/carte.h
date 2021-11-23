#ifndef CARTE_H
#define CARTE_H

#include <vector>
#include "../Classes/point.h"

using namespace std;

class SommetC
{
	friend class Carte;
	friend class DemiCote;

private:

	// Construit un sommet avec les coordonn�es de p
	SommetC(const Point &p) : d_coordonnees(p) {};

	// Destructeur de sommet priv�
	~SommetC() = default;

	Point d_coordonnees;
};

class DemiCote
{
	friend class Carte;

public:

    // Renvoie l'adresse du demi-c�t� suivant dans le sens trigonom�trique
	DemiCote* suivant() const {return d_suivant;}

    // Renvoie l'adresse du demi-c�t� precedent dans le sens trigonom�trique
	DemiCote* precedent() const {return d_precedent;}

    // Renvoie l'adresse du demi-c�t� oppos�
	DemiCote* oppose() const {return d_oppose;}

	// Renvoie les coordonn�es du sommet dont est issu le demi-c�t�
    Point coordonnees() const {return d_sommet->d_coordonnees;}

	// Renvoie le num�ro du demi-c�t�
    int numero() const {return d_numero;}

    // Renvoie la marque du demi-c�t�
	int marque() const {return d_marque;}

    // Met la marque du demi-c�t� � m
	void changeMarque(int m) const {const_cast<int&>(d_marque) = m;}

private:

	// Construit un demi-c�t� dont suivant est le demi-c�t� suivant, precedent est le demi-c�t� pr�c�dent,
	// oppose est le demi-c�t� oppos�, sommet est le sommet dont il est issu et numero est le num�ro
	DemiCote(DemiCote* suivant, DemiCote* precedent, DemiCote* oppose, SommetC* sommet, int numero)
        : d_suivant{suivant}, d_precedent{precedent}, d_oppose{oppose}, d_sommet{sommet}, d_numero{numero}, d_marque{0} {};

	// Destrusteur de demi-c�t� priv�
	~DemiCote() = default;


	DemiCote* d_suivant;
	DemiCote* d_precedent;
	DemiCote* d_oppose;
	SommetC* d_sommet;
	int d_numero;       // la position du demi-c�t� dans le tableau d_tabDemiCote
	int d_marque;	    // la marque du demi-c�t� (0 par d�faut)
};

class Carte
{
public:

    // Constructeur par d�faut
    Carte() : d_demiCoteParticulier{nullptr} {}

	// Destructeur
	~Carte();

    // Renvoie le nombre de demi-c�t�s de la carte
	int nbDemiCote() const 	{return d_tabDemiCote.size();}

    // Renvoie l'adresse du i�me demi-c�t� du tableau de demi-c�t�s (0 <= i < nbDemiCotes())
	DemiCote* demiCote(int i) const	{return d_tabDemiCote[i];}

	// Renvoie l'adresse du demi-c�t� particulier de la carte
	DemiCote* demiCoteParticulier() const {return d_demiCoteParticulier;}

	// Modifie le demi-c�t� particulier de la carte
	void changeDemiCoteParticulier(DemiCote* particulier) {d_demiCoteParticulier = particulier;}

    // Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2 dont
    // precedent1 et precedent2 seront les demi-c�t�s pr�c�dents respectifs.
    // precedent1 et precedent2 doivent �tre effectivement pr�sents dans la carte.
    // Renvoie l'adresse de dc1.
	DemiCote* ajouteCote(DemiCote* precedent1, DemiCote* precedent2);

    // Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
    // precedent1 sera le demi-c�t� pr�c�dent de dc1. dc2 sera issu d�un
    // nouveau sommet (� cr�er) dont les coordonn�es sont celles du point p2.
    // precedent1 doit �tre effectivement pr�sent dans la carte.
    // Renvoie l'adresse de dc1.
	DemiCote* ajouteCote(DemiCote* precedent1, const Point& p2);

    // Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
    // precedent2 sera le demi-c�t� pr�c�dent de dc2. dc1 sera issu d�un
    // nouveau sommet (� cr�er) dont les coordonn�es sont celles du point p1.
    // precedent2 doit �tre effectivement pr�sent dans la carte.
    // Renvoie l'adresse de dc1.
	DemiCote* ajouteCote(const Point& p1, DemiCote* precedent2);

    // Ajoute dans la carte un nouveau c�t� compos� de deux demi-c�t�s dc1 et dc2.
    // dc1 et dc2 seront issus de deux nouveaux sommets (� cr�er) dont les coordonn�es
    // sont celles des points p1 et p2 respectivement.
    // Renvoie l'adresse de dc1.
	DemiCote* ajouteCote(const Point& p1, const Point& p2);

private:

	// Ajoute un nouveau demi-c�t� dans la carte dont precedent sera le demi-c�t� pr�c�dent et
	// oppose sera le demi-c�t� oppos�. On suppose que le demi-c�t� precedent est d�j� pr�sent dans la carte.
	// Le demi-c�t� oppose est soit d�j� pr�sent dans la carte soit nul (valeur par d�faut).
	// Renvoie l�adresse du nouveau demi-c�t�.
	DemiCote* ajouteDemiCote(DemiCote* precedent, DemiCote* oppose=nullptr);

	// Ajoute un nouveau demi-c�t� dans la carte qui sera issu d�un nouveau sommet (� cr�er)
	// dont les coordonn�es sont celles du point p.	oppose sera le demi-c�t� oppos� du nouveau demi-c�t�.
	// oppose est soit d�j� pr�sent dans la carte soit nul (valeur par d�faut).
	// Renvoie l�adresse du nouveau demi-c�t�.
	DemiCote* ajouteDemiCote(const Point &p, DemiCote* oppose=nullptr);


	vector<DemiCote*> d_tabDemiCote;

	DemiCote* d_demiCoteParticulier;
};

#endif
