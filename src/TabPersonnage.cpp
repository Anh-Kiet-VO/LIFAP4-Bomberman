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
    ///////// TABBOMBE /////////

    //Vérification getNbPerso
    assert(getNbPerso() == 1);

    //Vérification de setNbPerso
    setNbPerso(4);
    assert(nbPerso == 4);

    //Vérification de la taille du tabPerso
    tabPerso.resize(2);
    assert(tabBombe.size() == 2);
}