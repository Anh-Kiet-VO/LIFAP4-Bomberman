#include "Brique.h"
#include <cassert>
#include <stdlib.h>

#include <iostream>
using namespace std;

Brique::Brique(){
    posX = posY = 0;
    bonus = false;
    //typeBonus = "NULL";
    coulBrique = Couleur(0,0,0);
}

Brique::Brique(unsigned int x,unsigned int y, bool det, string typeBon, Couleur c){
    assert(x >= 0 && y >= 0);
    posX = x;
    posY = y;
    detruit = det;
    typeBonus = typeBon;
    coulBrique = c;
}

unsigned int Brique::getPosX() const{
    return posX;
}

unsigned int Brique::getPosY() const{
    return posY;
}