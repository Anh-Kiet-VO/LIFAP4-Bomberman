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

bool TabBrique::getDetruit(unsigned int bri){
    return tabBrique[bri].detruit;
}

void TabBrique::setDetruit(unsigned int bri, bool det){
    tabBrique[bri].detruit = det;
}

void TabBrique::testRegression(){
    cout << nbBrique <<endl;
    assert(getNbBrique() == 1);
    setNbBrique(5);
    cout << nbBrique << endl;
    assert(getNbBrique() == 5);
    
    vector<TabBrique> tab_br;
    tab_br.resize(5);
<<<<<<< HEAD
    assert(tab_br.getDetruit(0) == 0);
    tab_br.setDetruit(0,false);
    assert(tab_br.getDetruit(0) == false);
=======
    assert(tab_br[0].getDetruit(0) == 0);
    tab_br[0].setDetruit(0,false);
    assert(tab_br[0].getDetruit(0) == false);
>>>>>>> 22792450f80b1ca23e6ab236f4c6a011fff4d8e5
}