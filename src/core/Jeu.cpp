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

Bombe& Jeu::getBombe(int j){ 
	if( j == 0){
		return b1; 
	}
	if( j == 1){
		return b2;
	}
}

const Terrain& Jeu::getConstTerrain() const { return ter; }

const Personnage& Jeu::getConstPerso(int i) const { 
	if( i == 0){
		return perso; 
	}
	if( i == 1){
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

void Jeu::PlacerBombe(Personnage& po, Terrain& ter, Bombe& b){
		//on place la bombe aux coordonnées du perso
		ter.placer(po.getPosX(), po.getPosY());	
}

void Jeu::UpdatePosBombe(Personnage& po, Terrain& ter, Bombe& b){
	//update des positions de la bombe
	b.setPos(po.getPosX(), po.getPosY());
}

void Jeu::ExploserBombe(Personnage& po, Terrain& ter, Bombe& b){ 
	//if((ter.getXY(po.getPosX(),po.getPosY())=='.' || ter.getXY(po.getPosX(),po.getPosY())==' ')){
		ter.EstExplosee(b.getPosX() + b.getPortee(), b.getPosY());
		ter.EstExplosee(b.getPosX() - b.getPortee(), b.getPosY());
		ter.EstExplosee(b.getPosX(), b.getPosY() - b.getPortee());
		ter.EstExplosee(b.getPosX(), b.getPosY() + b.getPortee());
		cout << "position bombe x " << b.getPosX() << endl;
		cout << "position bombe y " << b.getPosY() << endl;
	//}
}

/*
void Jeu::PlaceEtExplose(Personnage& po, Terrain& ter, Bombe& b){
	if((ter.getXY(po.getPosX(),po.getPosY())=='.' || ter.getXY(po.getPosX(),po.getPosY())==' ')){
        //on place la bombe aux coordonnées du perso
        ter.placer(po.getPosX(), po.getPosY());    
	    //update des positions de la bombe
	    b.setPos(po.getPosX(), po.getPosY());
        //explosion en fonction de la position de la bombe
        ter.EstExplosee(b.getPosX() + b.getPortee(), b.getPosY());
        ter.EstExplosee(b.getPosX() - b.getPortee(), b.getPosY());
        ter.EstExplosee(b.getPosX(), b.getPosY() - b.getPortee());
        ter.EstExplosee(b.getPosX(), b.getPosY() + b.getPortee());
        cout << "position bombe x " << b.getPosX() << endl;
        cout << "position bombe y " << b.getPosY() << endl;
	}
}*/

bool Jeu::actionClavier(const char touche) {
	//int briq = ter.bri.getNbBrique();
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
		//stock start d'une bombe, p initialise start, et on laise prog retourner son main
		//30Hertz/tt seconde on verif etat boucle principale
		//si compteur arrivé à 0 on lance explosion	

				PlacerBombe(perso, ter, b1);
				UpdatePosBombe(perso, ter, b1);
								
				//PlaceEtExplose(perso, ter, b1);
				//PlacerBombe(perso, ter, b1);
				//ExploserBombe(perso, ter, b1); //METTRE EN COMME QUAND SDL
				/*if(ter.getXY(b1.getPosX() + 2, b1.getPosY()) == '.' && ter.getXY(b1.getPosX() + 2, b1.getPosY()) != ' '){
					briq--;
					ter.bri.setNbBrique(briq);
					cout << "nombre brique : " << ter.bri.getNbBrique() << endl;
				}
				
				
				if(ter.bri.getNbBrique() == 0){
					cout << "gagné" << endl;
					ter.bri.setNbBrique(0);
				}*/
				break;
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 2e JOUEUR ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
				cout<<"On place une bombe haha...";
				//PlaceEtExplose(in_perso, ter, b2);
				break;
	}
	/*if((ter.getXY(perso[1].getPosX(),perso[1].getPosY())=='.' || ter.getXY(perso[1].getPosX(),perso[1].getPosY())==' ')){
		//ter.placer(perso[1].getPosX(), perso[1].getPosY());
		ter.EstExplosee(perso[1].getPosX() + b.getPortee(), perso[1].getPosY());
		ter.EstExplosee(perso[1].getPosX() - b.getPortee(), perso[1].getPosY());
		ter.EstExplosee(perso[1].getPosX(), perso[1].getPosY() - b.getPortee());
		ter.EstExplosee(perso[1].getPosX(), perso[1].getPosY() + b.getPortee());
		return true;
	}*/
	return false;
}