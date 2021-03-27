#include "Bombe.h"
#include <cassert>

Bombe::Bombe() {
  posX = posY = 0;
  portee = 0;
  tempsExplosion = 4;
}

Bombe::Bombe(unsigned int positionX, unsigned int positionY, int nouvPortee) {
  assert(positionX >= 0);
  assert(positionY >= 0);
  posX = positionX;
  posY = positionY;
  portee = nouvPortee;
}

unsigned int Bombe::getPosX() const {
  assert(posX >= 0);
  return posX;
}

unsigned int Bombe::getPosY() const {
  assert(posY >= 0);
  return posY;
}

void Bombe::setPos(unsigned int x, unsigned int y) {
  assert(x >= 0);
  assert(y >= 0);
  posX = x;
  posY = y;
}

int Bombe::getPortee() const {
  return portee;
}

void Bombe::setPortee(int p) {
  portee = p;
}