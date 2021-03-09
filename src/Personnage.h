 /**
  * @brief Module gérant le Personnage, ainsi que leurs fonctions associées
  * @file Personnage.h
  * @date 06/03/2021
*/

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Couleur.h"
#include <string>
using namespace std;

class Personnage {
	private:
	/**
	 * @brief Nom du joueur
	*/
	string nom;

	/**
	 * @brief Couleur R,V,B du personnage
	*/
	Couleur coulPerso;

	/**
	 * @brief Booléen pour savoir si le joueur est en vie
	*/
	bool vivant;

	/**
	 * @brief Vitesse en x et y du personnage
	*/
	float vitesseX, vitesseY;

	public:
	/**
	 * @brief Position en x et y du personnage
	*/
	int posX, posY;

	/**
	 * @brief Tableau de bombes du personnage
	*/

	/**
	 * @brief Les composantes d'une couleur
	*/
	Personnage();

	/**
	 * @brief Création du personnage de l'utilisateur
	 * @param pnom : Chaîne de caractère
	 * @param x : Entier
	 * @param y : Entier
	*/
	Personnage(string &pnom, int x, int y);

	/**
	 * @brief Destruction du personnage de l'utilisateur
	*/
	~Personnage();

	/**
	 * @brief Accesseur pour la position en x
	*/
	int getPosX() const;

	/**
	 * @brief Accesseur pour la position en y
	*/
	int getPosY() const;

	/**
	 * @brief Accesseur pour la vitesse en x
	*/
	int getVitesseX() const;

	/**
	 * @brief Accesseur pour la vitesse en y
	*/
	int getVitesseY() const;

	/**
	 * @brief Mutateur pour la position en x
	 * @param x : Entier
	*/
	void setPosX(const int &x);

	/**
	 * @brief Mutateur pour la position en y
	 * @param y : Entier
	*/
	void setPosY(const int &y);

	/**
	 * @brief Mutateur pour la vitesse en x,y
	 * @param x : Entier
	 * @param y : Entier
	*/
	void setVitesse(const int &x, const int &y);

	/**
	 * @brief Deplacement du personnage
	 * @param Terrain : Classe Terrain
	 * @param jsp : Entier
	*/
	
};

#endif