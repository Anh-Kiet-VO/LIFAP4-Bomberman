#include "TabBrique.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

TabBrique::TabBrique(){
    nbBrique = 0;
    //tabBrique = vector<Brique> tabBrique(0);
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

Brique TabBrique::getBrique(int i){
    return tabBrique[i];
}

bool TabBrique::getDetruit(unsigned int bri){
    return tabBrique[bri].detruit;
}

void TabBrique::setDetruit(unsigned int bri, bool det){
    tabBrique[bri].detruit = det;
}

