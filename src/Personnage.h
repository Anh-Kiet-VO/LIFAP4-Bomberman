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
<<<<<<< HEAD
	 * @brief Mutateur pour la position en x
=======
	 * @brief Mutateur pour la position en X
>>>>>>> 879a701c96dc348852f082798bf9b13844d14b47
	 * @param x : entier
	*/
	void setPosX(const unsigned int &x);

	/**
<<<<<<< HEAD
	 * @brief Mutateur pour la position en y
=======
	 * @brief Mutateur pour la position en Y
>>>>>>> 879a701c96dc348852f082798bf9b13844d14b47
	 * @param y : entier
	*/
	void setPosY(const unsigned int &y);

	/**
<<<<<<< HEAD
	 * @brief Mutateur pour la vitesse en x,y
=======
	 * @brief Mutateur pour la vitesse en X, Y
>>>>>>> 879a701c96dc348852f082798bf9b13844d14b47
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