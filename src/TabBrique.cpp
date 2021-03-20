#include "TabBrique.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

TabBrique::TabBrique(){
    nbBrique = 0;
    vector<Brique> tabBrique(nbBrique);
}

TabBrique::TabBrique(vector<Brique> tab, unsigned int n){
    nbBrique = n;
    tabBrique = tab;
}

TabBrique::~TabBrique(){
    nbBrique = 0;
    //tabBrique = 0;
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

bool TabBrique::getDetruit(unsigned int bri){
    return tabBrique[bri].detruit;
}

void TabBrique::setDetruit(unsigned int bri, bool det){
    tabBrique[bri].detruit = det;
}

void TabBrique::testRegression(){
    TabBrique tab_br;
    assert(getNbBrique() == 0);
    setNbBrique(5);
    assert(getNbBrique() == 5);
    
    assert(tab_br.getDetruit(0) == true);
    tab_br.setDetruit(0,false);
    assert(tab_br.getDetruit(0) == false);
}
