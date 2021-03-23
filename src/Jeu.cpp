#include "Jeu.h"

Jeu::Jeu () : ter(), perso() {

}

Terrain& Jeu::getTerrain() { return ter; }

Personnage& Jeu::getPerso() {	return perso; }

const Terrain& Jeu::getConstTerrain () const { return ter; }

const Personnage& Jeu::getConstPerso () const { return perso; }

bool Jeu::actionClavier (const char touche) {
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
	}
	return false;
}
