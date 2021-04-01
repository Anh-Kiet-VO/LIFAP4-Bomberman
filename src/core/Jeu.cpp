#include "Jeu.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
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
				cout<<"gauche : " << perso.getPosX() << " " << perso.getPosY() << endl; 
				break;
		case 'd' :
				perso.droite(ter);
				cout<<"droite : " << perso.getPosX() << " " << perso.getPosY() << endl; 
				break;
		case 'h' :
				perso.haut(ter);
				cout<<"bas : " << perso.getPosX() << " " << perso.getPosY() << endl; 
				break;
		case 'b' :
				perso.bas(ter);
				cout<<"haut : " << perso.getPosX() << " " << perso.getPosY() << endl; 
				break;
		case 'n' :
				//ter.placer(perso.getPosX(), perso.getPosY());
				
				if((ter.getXY(perso.getPosX(),perso.getPosY())=='.' || ter.getXY(perso.getPosX(),perso.getPosY())==' ')){
					//on place la bombe aux coordonnées du perso
					ter.placer(perso.getPosX(), perso.getPosY());	
					//update des positions de la bombe
					b.setPos(perso.getPosX(), perso.getPosY());
					//explosion en fonction de la position de la bombe
					ter.EstExplosee(b.getPosX() + b.getPortee(), b.getPosY());
					ter.EstExplosee(b.getPosX() - b.getPortee(), b.getPosY());
					ter.EstExplosee(b.getPosX(), b.getPosY() - b.getPortee());
					ter.EstExplosee(b.getPosX(), b.getPosY() + b.getPortee());
					cout << "position bombe x " << b.getPosX() << endl;
					cout << "position bombe y " << b.getPosY() << endl;
				}
				break;
	}
	/*if((ter.getXY(perso.getPosX(),perso.getPosY())=='.' || ter.getXY(perso.getPosX(),perso.getPosY())==' ')){
		//ter.placer(perso.getPosX(), perso.getPosY());
		ter.EstExplosee(perso.getPosX() + b.getPortee(), perso.getPosY());
		ter.EstExplosee(perso.getPosX() - b.getPortee(), perso.getPosY());
		ter.EstExplosee(perso.getPosX(), perso.getPosY() - b.getPortee());
		ter.EstExplosee(perso.getPosX(), perso.getPosY() + b.getPortee());
		return true;
	}*/
	return false;
}
