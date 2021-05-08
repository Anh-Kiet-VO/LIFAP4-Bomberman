#include "Jeu.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
using namespace std;
Jeu::Jeu () : ter(), perso(), in_perso(13,9), b1(), b2(), bom() {
}

Terrain& Jeu::getTerrain() { return ter; }

Personnage& Jeu::getPerso(int i) {
	if( i == 0){
		return perso; 
	}
	if( i == 1){
		return in_perso;
	}
}

Bombe& Jeu::getBombe(int j) { 
	if( j == 0){
		return b1; 
	}
	if( j == 1){
		return b2;
	}
}

const Terrain& Jeu::getConstTerrain() const { return ter; }

const Personnage& Jeu::getConstPerso(int i) const { 
	if( i == 0) {
		return perso; 
	}
	if( i == 1) {
		return in_perso;
	}
}

const Bombe& Jeu::getConstBombe(int j) const { 
	if( j == 0){
		return b1; 
	}
	if( j == 1){
		return b2;
	}
}

void Jeu::placerBombe(Personnage& po, Terrain& ter, Bombe& b) {
	//on place la bombe aux coordonnées du perso
	ter.placer(po.getPosX(), po.getPosY());
	b.estSurLeTerrain = true;
}

void Jeu::updatePosBombe(Personnage& po, Terrain& ter, Bombe& b) {
	//update des positions de la bombe
	b.setPos(po.getPosX(), po.getPosY());
}

void Jeu::exploserBombe(Personnage& po, Terrain& ter, Bombe& b) { 
	ter.estExplosee(b.getPosX() + b.getPortee(), b.getPosY());
	ter.estExplosee(b.getPosX() - b.getPortee(), b.getPosY());
	ter.estExplosee(b.getPosX(), b.getPosY() - b.getPortee());
	ter.estExplosee(b.getPosX(), b.getPosY() + b.getPortee());
	cout << "position bombe x " << b.getPosX() << endl;
	cout << "position bombe y " << b.getPosY() << endl;
	ter.bombeEstExplosee(b.getPosX(), b.getPosY());	
	b.estSurLeTerrain = false;
}

void Jeu::tuerPerso(Personnage& po, Terrain& ter, Bombe& b) {
	/*ter.estTuee(po.getPosX() + b.getPortee(), po.getPosY());
	ter.estTuee(po.getPosX() - b.getPortee(), po.getPosY());
	ter.estTuee(po.getPosX(), po.getPosY() + b.getPortee());
	ter.estTuee(po.getPosX(), po.getPosY() - b.getPortee());
	cout << "mort" << endl;*/
}

bool Jeu::actionClavier(const char touche) {
	switch(touche) {
		// Commandes du 1er joueur
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
			placerBombe(perso, ter, b1);
			updatePosBombe(perso, ter, b1);
			break;
		// Commandes du 2e joueurs
		case 'f' :
			in_perso.gauche(ter);
			cout<<"perso2 gauche : " << in_perso.getPosX() << " " << in_perso.getPosY() << endl; 
			break;
		case 'c' :
			in_perso.droite(ter);
			cout<<"perso2 droite : " << in_perso.getPosX() << " " << in_perso.getPosY() << endl; 
			break;
		case 'v' :
			in_perso.haut(ter);
			cout<<"perso2 bas : " << in_perso.getPosX() << " " << in_perso.getPosY() << endl; 
			break;
		case 'j' :
			in_perso.bas(ter);
			cout<<"perso2 haut : " << in_perso.getPosX() << " " << in_perso.getPosY() << endl; 
			break;
		case 'u' :
			placerBombe(in_perso, ter, b2);
			updatePosBombe(in_perso, ter, b2);
			break;
	}
	return false;
}