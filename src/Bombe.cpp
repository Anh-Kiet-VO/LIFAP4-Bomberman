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

unsigned int Bombe::getPosX() const {
  return posX;
}

unsigned int Bombe::getPosY() const {
  return posY;
}

unsigned int Bombe::getPortee() const {
  return portee;
}

void Bombe::setPortee(unsigned int p) {
    portee = p;
}