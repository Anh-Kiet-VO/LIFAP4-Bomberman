#include "TabBrique.h"
#include <cassert>
#include <stdlib.h>

#include <iostream>
using namespace std;

TabBrique::TabBrique(){
    nbBrique = 0;
    //tabBrique = new tabBrique[];
}

TabBrique::TabBrique(vector<Brique> tab, unsigned int n){
    nbBrique = n;
    //tabBrique = tab;
}

TabBrique::~TabBrique(){

}

unsigned int TabBrique::getNbBrique(){
    assert(nbBrique >= 0);
    return nbBrique;
}

bool TabBrique::getDetruit(unsigned int bri){
    /*for(unsigned int = 0 ; i < nbBrique ; i++){
        return tabBrique[bri].detruit;
    }  */
}

void TabBrique::setDetruit(unsigned int bri, bool det){
    for(int i = 0 ; i < nbBrique ; i++){
        tabBrique[bri].detruit = det;
    }
}

