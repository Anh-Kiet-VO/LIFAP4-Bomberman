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
	assert(x >= 1 && y >= 1);

	nom = pnom;

	x = posX;
	y = posY;

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

void Personnage::testRegression() {
	setPosX(5);
	setPosY(5);

	assert(getPosX() == 5 && getPosY() == 5);

	assert(vitesseX >= 1 && vitesseY >= 1);

	setVitesse(5, 5);

	assert(getVitesseX() == 5 && getVitesseY() == 5);

	string pseudo = "joueur";
	Personnage(pseudo, 1, 1);

	assert(nom == "joueur");
	assert(posX >= 1 && posY >= 1);

	Couleur coul (31, 68, 50);
	
	assert(coul.getRouge() == 31);
	assert(coul.getVert() == 68);
	assert(coul.getBleu() == 50);
	
	coul.setRouge(78);
	coul.setVert(12);
	coul.setBleu(104);

	assert(coul.getRouge() == 78);
	assert(coul.getVert() == 12);
	assert(coul.getBleu() == 104);

	assert(vivant != false);
}