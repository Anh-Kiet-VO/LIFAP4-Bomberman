#include "Bombe.h"
#include <cassert>

Bombe::Bombe() {
  posX = posY = 0;
  portee = 0;
}

Bombe::Bombe(unsigned int positionX, unsigned int positionY, int nouvPortee) {
  assert(positionX >= 0);
  assert(positionY >= 0);
  posX = positionX;
  posY = positionY;
  portee = nouvPortee;
}

Bombe::~Bombe() {
  posX = posY = 0;
  portee = 0;
}

unsigned int Bombe::getPosX() const {
  assert(posX >= 0);
  return posX;
}

unsigned int Bombe::getPosY() const {
  assert(posY >= 0);
  return posY;
}

unsigned int Bombe::getPortee() const {
  return portee;
}

void Bombe::setPortee(int p) {
  portee = p;
}