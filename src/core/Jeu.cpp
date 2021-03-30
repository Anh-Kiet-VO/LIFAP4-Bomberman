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
				cout<<"gauche : " << perso.getPosX() << " " << perso.getPosY() << endl; 
				break;
		case 'd' :
				perso.droite(ter);
				cout<<"droite : " << perso.getPosX() << " " << perso.getPosY() << endl; 
				break;
		case 'h' :
				perso.haut(ter);
				break;
		case 'b' :
				perso.bas(ter);
				cout<<"bas : " << perso.getPosX() << " " << perso.getPosY() << endl; 
				break;
		case 'n' :
<<<<<<< HEAD:src/core/Jeu.cpp
				ter.placer(perso.getPosX(), perso.getPosY());
				cout<<b.getPosX() << " " <<b.getPosY() << endl;
=======
				//ter.placer(perso.getPosX(), perso.getPosY());
				if((ter.getXY(perso.getPosX(),perso.getPosY())=='.' || ter.getXY(perso.getPosX(),perso.getPosY())==' ')){
					ter.placer(perso.getPosX(), perso.getPosY());
					ter.EstExplosee(perso.getPosX() + b.getPortee(), perso.getPosY());
					ter.EstExplosee(perso.getPosX() - b.getPortee(), perso.getPosY());
					ter.EstExplosee(perso.getPosX(), perso.getPosY() - b.getPortee());
					ter.EstExplosee(perso.getPosX(), perso.getPosY() + b.getPortee());
				}
>>>>>>> 6107eb83283d8318662aa6768201a59ed99fd652:src/Jeu.cpp
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
