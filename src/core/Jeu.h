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
    Bombe b1;
    Bombe b2;
	
	public:
        /**
         * @brief Mutateur : modifie la position de la bombe
        */
        Jeu();

        Terrain& getTerrain();
        Personnage& getPerso(int i);
        Bombe& getBombe(int j);

        /**
         * @brief accesseur : permet d'accéder au terrain
        */
        const Terrain& getConstTerrain() const;

        /**
         * @brief accesseur : permet d'accéder à un personnage
         * @param i : entier
        */
        const Personnage& getConstPerso(int i) const;

        /**
         * @brief accesseur : permet d'accéder à une bombe
         * @param j : entier
        */
        const Bombe& getConstBombe(int j) const;

        
        /*void ExploserBombe(Personnage& po, Terrain& ter, Bombe& b);

        void PlacerBombe(Personnage& po, Terrain& ter, Bombe& b);*/

        /**
         * @brief Permet de placer et de faire exploser les briques autour d'une bombe
         * @param j : entier
         * @param po : personnage
         * @param ter : terrain
         * @param b : bombe
        */
        void PlaceEtExplose(Personnage& po, Terrain& ter, Bombe& b);

        /**
         * @brief Permet de réaliser une action en appuyant sur une touche du clavier
         * @param touche : caractère
        */
        bool actionClavier(const char touche);
};

#endif
