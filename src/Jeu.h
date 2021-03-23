/**
 * @brief Module grant le Jeu
 * @file Jeu.h
 * @date 20/03/2021
*/


#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"

class Jeu {
	private:
	Terrain ter;
	Personnage perso;
	
	public:
    Jeu();

    Terrain& getTerrain();
    Personnage& getPerso();

    const Terrain& getConstTerrain() const;
    const Personnage& getConstPerso() const;

    bool actionClavier(const char touche);
};

#endif
