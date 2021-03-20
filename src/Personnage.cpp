#include "Personnage.h"
#include <cassert>

Personnage::Personnage() {
	posX = posY = 1;
	vitesseX = vitesseY = 1;
	vivant = true;
	coulPerso = Couleur(0,0,0);

	TabBombe bombes;
}

Personnage::Personnage(string &pnom, unsigned int x, unsigned int y) {
	assert(x >= 0 && y >= 0);

	nom = pnom;

	x = posX;
	y = posY;

	setPosX(x);
	setPosY(y);

	vitesseX = vitesseY = 1;
	vivant = true;
	
	coulPerso = Couleur(255,255,255);

	TabBombe bombes;
}

Personnage::~Personnage() {
	nom = "";
	vivant = false;
	vitesseX = vitesseY = 0.0;
	posX = posY = 0;
}

int Personnage::getPosX() const {
	return posX;
}

int Personnage::getPosY() const {
	return posY;
}

int Personnage::getVitesseX() const {
	return vitesseX;
}

int Personnage::getVitesseY() const {
	return vitesseY;
}

void Personnage::setPosX(const unsigned int &x) {
	assert(posX >= 0);
	posX = x;
}

void Personnage::setPosY(const unsigned int &y) {
	assert(posY >= 0);
	posY = y;
}

void Personnage::setVitesse(const float &x, const float &y) {
	assert(vitesseX > 0 && vitesseY > 0);
	vitesseX = x;
	vitesseY = y;
}

void Personnage::gauche(const Terrain &t) {
	if(t.estPosValid(posX-1,posY)) posX--;
}

void Personnage::droite(const Terrain &t) {
	if(t.estPosValid(posX+1,posY)) posX++;
}

void Personnage::haut(const Terrain &t) {
	if (t.estPosValid(posY,posY+1)) posY++;
}

void Personnage::bas(const Terrain &t) {
	if (t.estPosValid(posY,posY-1)) posY--;
}