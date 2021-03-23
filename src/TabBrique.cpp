#include "TabBrique.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

TabBrique::TabBrique(){
    nbBrique = 1;
    vector<Brique> tabBrique;
    tabBrique.resize(nbBrique);
}

TabBrique::~TabBrique(){
    nbBrique = 0;
    tabBrique.clear();
}

unsigned int TabBrique::getNbBrique(){
    assert(nbBrique >= 0);
    return nbBrique;
}

void TabBrique::setNbBrique(unsigned int nouvNbBrique){
    assert(nouvNbBrique >= 0);
    nbBrique = nouvNbBrique;
}

Brique TabBrique::getBrique(int i){
    return tabBrique[i];
}

void TabBrique::testRegression(){
    assert(getNbBrique() == 1);
    setNbBrique(5);
    assert(getNbBrique() == 5);

    Brique bri;
    assert(bri.posX == 0 && bri.posY == 0);
    bri.setPosXY(5,7);
    assert(bri.getPosX() == 5 && bri.getPosY() == 7);

    assert(bri.bonus == false);
    
    assert(bri.detruit == false);
    bri.setDetruit(true);
    assert(bri.getDetruit() == true);
}