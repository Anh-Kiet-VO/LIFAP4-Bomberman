#include "Personnage.h"
#include <cassert>

Personnage::Personnage() {
	posX = posY = 1;
	vitesseX = vitesseY = 1;
	vivant = true;
	coulPerso = Couleur(0,0,0);
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
}

Personnage::~Personnage() {
	nom = "";
	vivant = false;
	vitesseX = vitesseY = 0.0;
	posX = posY = 0;
	//bombe = NULL;

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

void Personnage::moveLeft(const Terrain &t) {
	if(t.isValidPos(posX-1,posY)) posX--;
}

void Personnage::moveRight(const Terrain &t) {
	if(t.isValidPos(posX+1,posY)) posX++;
}

void Personnage::moveUp(const Terrain &t) {
	if (t.isValidPos(posY,posY+1)) posY++;
}

void Personnage::moveDown(const Terrain &t) {
	if (t.isValidPos(posY,posY-1)) posY--;
}

// ================================== PAS FINI ================================
/*
void Personnage::deplacement() {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(),jeu.getConstTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

		jeu.actionsAutomatiques();

		c = win.getCh();
		switch (c) {
			case 'z':
				jeu.actionClavier('z');
				break;
			case 's':
				jeu.actionClavier('s');
				break;
			case 'q':
				jeu.actionClavier('q');
				break;
			case 'd':
				jeu.actionClavier('d');
				break;
		}

	} while (ok);
}
*/