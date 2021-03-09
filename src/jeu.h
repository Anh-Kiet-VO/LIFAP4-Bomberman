/**
@brief Module Jeu (du Bomberman)

@file Jeu.h
@date 09/03/2021
*/

#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"
#include "tabBrique.h"

/**
 * @brief Le bomberman est un terrain avec des briques à détruire et (de pacman) = un terrain et un pacman
*/
class Jeu {

private :

	Terrain ter;
	Pacman pac;
	Fantome fan;

public :

    Jeu ();

    Terrain& getTerrain ();
    Pacman& getPacman ();

    const Terrain& getConstTerrain () const;
    const Pacman& getConstPacman () const;
    const Fantome& getConstFantome () const;
    int getNombreDeFantome() const;

    void actionsAutomatiques ();
    bool actionClavier(const char touche); // rend vrai si mange une pastille, faux sinon

};

#endif
