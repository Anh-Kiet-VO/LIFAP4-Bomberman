#include "Jeu.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
using namespace std;
Jeu::Jeu () : ter(), perso(), in_perso(13,9), b() {
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

Bombe& Jeu::getBombe(){ return b; }

const Terrain& Jeu::getConstTerrain() const { return ter; }

const Personnage& Jeu::getConstPerso(int i) const { 
	if( i == 0){
		return perso; 
	}
	if( i == 1){
		return in_perso;
	}
}

const Bombe& Jeu::getConstBombe() const { return b; }
/*
void Jeu::PlacerBombe(Personnage& perso, Terrain& ter, Bombe& b){
	if((ter.getXY(perso.getPosX(),perso.getPosY())=='.' || ter.getXY(perso.getPosX(),perso.getPosY())==' ')){
		//on place la bombe aux coordonnées du perso
		ter.placer(perso.getPosX(), perso.getPosY());	
		//update des positions de la bombe
		b.setPos(perso.getPosX(), perso.getPosY());
	}
}

void Jeu::ExploserBombe(Personnage& perso, Terrain& ter, Bombe& b){ //nom perso
	if((ter.getXY(perso.getPosX(),perso.getPosY())=='.' || ter.getXY(perso.getPosX(),perso.getPosY())==' ')){
		ter.EstExplosee(b.getPosX() + b.getPortee(), b.getPosY());
		ter.EstExplosee(b.getPosX() - b.getPortee(), b.getPosY());
		ter.EstExplosee(b.getPosX(), b.getPosY() - b.getPortee());
		ter.EstExplosee(b.getPosX(), b.getPosY() + b.getPortee());
		cout << "position bombe x " << b.getPosX() << endl;
		cout << "position bombe y " << b.getPosY() << endl;
	}
}*/

void Jeu::PlaceEtExplose(Personnage& perso, Terrain& ter, Bombe& b){
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
}

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
		//stock start d'une bombe, p initialise start, et on laise prog retourner son main
		//30Hertz/tt seconde on verif etat boucle principale
		//si compteur arrivé à 0 on lance explosion	

				//ter.placer(perso.getPosX(), perso.getPosY());
		
				//PlacerBombe(perso, ter, b);
				//auto start = chrono::system_clock::now();
				//auto end = chrono::system_clock::now();
				/*while(chrono::duration_cast<chrono::seconds>(end - start).count() < 2.0){
					//diff entre 2 now /seconde/ms maj j et end -> now
					end = chrono::system_clock::now(); 
				}*/
				cout << "kaboom" << endl;
				PlaceEtExplose(perso, ter, b);
						
				cout << "nombre brique : " << ter.bri.getNbBrique() << endl;
				//ter.bri.setNbBrique(ter.bri.getNbBrique()--);
				cout << ter.bri.getNbBrique() << endl;
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