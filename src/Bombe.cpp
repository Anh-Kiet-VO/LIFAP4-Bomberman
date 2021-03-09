#include "Bombe.h"

Bombe::Bombe() {
    posX = posY = 0;
    portee = 0;
}

Bombe::Bombe(unsigned int positionX, unsigned int positionY, unsigned int nouvPortee) {
    posX = positionX;
    posY = positionY;
    portee = nouvPortee;
}

Bombe::~Bombe() {
    posX = posY = 0;
    portee = 0;
}

