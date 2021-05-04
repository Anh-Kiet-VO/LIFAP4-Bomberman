#include "Bombe.h"
#include <cassert>
#include <chrono>

Bombe::Bombe() {
  posX = posY = 1;
  portee = 1;
  tempsExplosion = 0;
  estSurLeTerrain = true;
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

int Bombe::getTempsExplo() {
  return tempsExplosion;
}

void Bombe::setTempsExplo(int t) {
  tempsExplosion = t;
}

void Bombe::compteurExplo() {
  auto debut = std::chrono::system_clock::now();
	auto fin = std::chrono::system_clock::now();
	while(std::chrono::duration_cast<std::chrono::seconds>(fin - debut).count() < 2.0){
		//diff entre 2 now /seconde/ms maj j et end -> now
		fin = std::chrono::system_clock::now(); 
	}
}