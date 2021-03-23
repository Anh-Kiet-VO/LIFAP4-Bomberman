#include "TabBombe.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

using namespace std;

TabBombe::TabBombe(){
    nbBombe = 1;
    vector<Bombe> tabBombe(nbBombe);
}

TabBombe::~TabBombe() {
    tabBombe.~vector();
}

unsigned int TabBombe::getNbBombe() const{
    assert(nbBombe > 0);
    return nbBombe;
}

void TabBombe::setNbBombe(unsigned int nouvNbBombe){
    assert(nouvNbBombe > 0);
    nbBombe = nouvNbBombe;
}

void TabBombe::testRegression(){
    //Vérification getNbBombe
    assert(getNbBombe() == 1);

    //Vérification de setNbBombe
    setNbBombe(4);
    assert(nbBombe == 4);
}