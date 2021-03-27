#include "TabPersonnage.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

TabPersonnage::TabPerso() {
    nbPerso = 1;
    vector<Personnage> tabPerso;
    tabPerso.resize(nbPerso);
}

TabPersonnage::~TabPerso() {
    tabPerso.clear();
}

unsigned int TabPersonnage::getNbPerso() const {
    assert(nbPerso > 0);
    return nbPerso;
}

void TabBombe::setNbPerso(unsigned int nouvNbPerso) {
    assert(setNbPerso > 0);
    nbPerso = nouvNbPerso;
}

void TabBombe::testRegression() {

	//Met les position X,Y à 5
	setPosX(5);
	setPosY(5);

	//Vérifie si la position est bien à 5
	assert(getPosX() == 5 && getPosY() == 5);

	//Vérifie si il a une vitesse en X,Y
	assert(vitesseX >= 1 && vitesseY >= 1);

	//Met la vitesse X,Y à 
	setVitesse(5, 5);

	//Vérifie si la vitesse est bien à 
	assert(getVitesseX() == 5 && getVitesseY() == 5);

	//Appel au constructeur Personnage
	string pseudo = "joueur";
	Personnage(pseudo, 5, 5);

	//vérifie si le nom du joueur est correct
	if(pseudo.compare(nom) == 0) cout << "Erreur avec le nom";

	//Vérifie si la position est bien à 
	assert(getPosX() == 5 && getPosY() == 5);

	Couleur coul (31, 68, 50);
	
	//Vérification des get
	assert(coul.getRouge() == 31);
	assert(coul.getVert() == 68);
	assert(coul.getBleu() == 50);
	
	coul.setRouge(78);
	coul.setVert(12);
	coul.setBleu(104);

	//Vérifie des get
	assert(coul.getRouge() == 78);
	assert(coul.getVert() == 12);
	assert(coul.getBleu() == 104);

	assert(vivant != false);

    ///////// TABBOMBE /////////

    //Vérification getNbPerso
    assert(getNbPerso() == 1);

    //Vérification de setNbPerso
    setNbPerso(4);
    assert(nbPerso == 4);

    //Vérification de la taille du tabPerso
    tabPerso.resize(2);
    assert(tabBombe.size() == 2);

    //Vérification de l'ajout d'une bombe
    tabBombe.push_back(une_bombe);
    assert(tabBombe[5].getPosX() == 5);
    assert(tabBombe[5].getPosY() == 7);
    assert(tabBombe[5].getPortee() == 3);
}