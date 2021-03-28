#include "Jeu.h"
#include <iostream>
using namespace std;
Jeu::Jeu () : ter(), perso(), b() {

}

Terrain& Jeu::getTerrain() { return ter; }

Personnage& Jeu::getPerso() { return perso; }

Bombe& Jeu::getBombe(){ return b; }

const Terrain& Jeu::getConstTerrain() const { return ter; }

const Personnage& Jeu::getConstPerso() const { return perso; }

const Bombe& Jeu::getConstBombe() const { return b; }

bool Jeu::actionClavier(const char touche) {
	switch(touche) {
		case 'g' :
				perso.gauche(ter);
				break;
		case 'd' :
				perso.droite(ter);
				break;
		case 'h' :
				perso.haut(ter);
				break;
		case 'b' :
				perso.bas(ter);
				break;
		case 'n' :
				ter.placer(perso.getPosX(), perso.getPosY());
				break;
	}
	
	return false;
}
