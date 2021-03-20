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
	 * @brief Vitesse en X et Y du personnage
	*/
	float vitesseX, vitesseY;

	public:
	/**
	 * @brief Position en X et Y du personnage
	*/
	unsigned int posX, posY;

	/**
	 * @brief Tableau de bombes du personnage
	*/

	/**
	 * @brief Les composantes d'une couleur
	*/
	Personnage();

	/**
	 * @brief Création du personnage de l'utilisateur
	 * @param pnom : chaîne de caractère
	 * @param x : entier
	 * @param y : entier
	*/
	Personnage(string &pnom, unsigned int x, unsigned int y);

	/**
	 * @brief Destruction du personnage de l'utilisateur
	*/
	~Personnage();

	/**
	 * @brief Accesseur pour la position en X
	*/
	int getPosX() const;

	/**
	 * @brief Accesseur pour la position en Y
	*/
	int getPosY() const;

	/**
	 * @brief Accesseur pour la vitesse en X
	*/
	int getVitesseX() const;

	/**
	 * @brief Accesseur pour la vitesse en Y
	*/
	int getVitesseY() const;

	/**
	 * @brief Mutateur pour la position en X
	 * @param x : entier
	*/
	void setPosX(const unsigned int &x);

	/**
	 * @brief Mutateur pour la position en Y
	 * @param y : entier
	*/
	void setPosY(const unsigned int &y);

	/**
	 * @brief Mutateur pour la vitesse en X, Y
	 * @param x : entier
	 * @param y : entier
	*/
	void setVitesse(const int &x, const int &y);

	/**
	 * @brief Déplacement du personnage
	 * @param Terrain : classe Terrain
	 * @param x : entier
	*/
	void deplacement();

	/**
	 * @brief Décremente la position en x
	*/
	void moveLeft();

	/**
	 * @brief Incrémente la position en x
	*/
	void moveRight();

	/**
	 * @brief Décremente la position en y
	*/
	void moveUp();

	/**
	 * @brief Décremente la position en y
	*/
	void moveDown();
};

#endif