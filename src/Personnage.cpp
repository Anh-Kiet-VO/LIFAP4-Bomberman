#include "Personnage.h"
#include <cassert>

Personnage::Personnage() {
	posX = 0;
	posY = 0;

}

Personnage::Personnage(string &pnom, int x, int y) {
	assert(x >= 0 && y >= 0);

	nom = pnom;

	x = posX;
	y = posY;

	setPosX(x);
	setPosY(y);

	vitesseX = vitesseY = 1;
	vivant = true;
	
	Couleur p = Couleur(255,255,255);
}

Personnage::~Personnage() {
	nom = "";
	vivant = false;
	vitesseX = vitesseY = NULL;
	bombe = NULL;

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

void Personnage::setPosX(const int &x) {
	assert(posX >= 0);
	posX = x;
}

void Personnage::setPosY(const int &y) {
	assert(posY >= 0);
	posY = y;
}

void Personnage::setVitesse(const int &x, const int &y) {
	assert(vitesseX > 0 && vitesseY > 0);
	vitesseX = x;
	vitesseY = y;
}