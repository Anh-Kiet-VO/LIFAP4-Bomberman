/**
 * @brief Module gérant le terrain du Bomberman
 * Le terrain dst un tableau 2D de caractère dont la taille est de dimX * dimY
 * @file Terrain.h
 * @date 09/03/2021
*/

#ifndef _TERRAIN_H
#define _TERRAIN_H


/**
 * @brief La classe Terrain contient ses dimensions et un tab 2D de cases (une case= 1 char)
*/

class Terrain {
	private:
	unsigned int dimX;
	unsigned int dimY;
	char ter[100][100];

	public:
	/**
	 * @brief Le constructeur remplit dimX et dimY et les cases du tableau ter avec un terrain par défaut
	*/
	Terrain();

	/**
	 * @brief Booléen qui renvoie vrai si on peut positionner le personnage en X,Y
	 * @param x : entier
	 * @param y : entier
	*/
	bool estPosValid(const unsigned int x, const unsigned int y) const;

    /**
	 * @brief Renvoie le type d'objet se trouvant en X,Y
	 * @param x : entier
	 * @param y : entier
    */
    char getXY(const unsigned int x, const unsigned int y) const;

	void EstExplosee(unsigned int x, unsigned int y);

	void placer(unsigned int x, unsigned int y);

    /**
	 * @brief Renvoie la largeur du terrain en X
    */
    int getDimX() const;

    /**
	 * @brief Renvoie la hauteur du terrain Y
    */
    int getDimY() const;

	/**
	 *  @brief Enlève le clignotement du curseur
	 * @param showFlag : booléen
	*/
	void ShowConsoleCursor(bool showFlag);
};

#endif