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

        /**
         * @brief terrain
        */
        Terrain ter;

        /**
         * @brief personnage1
        */
        Personnage perso;

        /**
         * @brief personnage2
        */
        Personnage in_perso;

        /**
         * @brief bombe pour personnage1
        */
        Bombe b1;

        /**
         * @brief bombe pour personnage2
        */
        Bombe b2;

        TabBrique bri;
        
	public:

        /**
         * @brief constructeur par défaut de la classe jeu
        */
        Jeu();

        /**
         * @brief accesseur : permet d'accéder au terrain
        */
        Terrain& getTerrain();

        /**
         * @brief accesseur : permet d'accéder à un personnage
         * @param i : entier
        */
        Personnage& getPerso(int i);

        /**
         * @brief accesseur : permet d'accéder à une bombe
         * @param j : entier
        */
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

        void UpdatePosBombe(Personnage& po, Terrain& ter, Bombe& b);

        void ExploserBombe(Personnage& po, Terrain& ter, Bombe& b);

        void PlacerBombe(Personnage& po, Terrain& ter, Bombe& b);

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
