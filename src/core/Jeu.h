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
    Personnage in_perso;
    Bombe b;
	
	public:
    Jeu();

    Terrain& getTerrain();
    Personnage& getPerso(int i);
    Bombe& getBombe();

    const Terrain& getConstTerrain() const;
    const Personnage& getConstPerso(int i) const;
    const Bombe& getConstBombe() const;

    void ExploserBombe(Personnage& po, Terrain& ter, Bombe& b);

    void PlacerBombe(Personnage& po, Terrain& ter, Bombe& b);

    void PlaceEtExplose(Personnage& po, Terrain& ter, Bombe& b);

    bool actionClavier(const char touche);
};

#endif
