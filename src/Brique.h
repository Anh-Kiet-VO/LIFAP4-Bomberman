/**
  @brief Module gérant une Brique
  @file Brique.h
  @date 09/03/2021
*/      

#ifndef BRIQUE_H
#define BRIQUE_H

#include "Couleur.h"
#include <string>

using namespace std;

class Brique{
    private:
        /**
         * @brief Le booléen pour indiquer si la brique est détruite
        */
        bool detruit;

        /**
         * @brief Le booléen pour indiquer si la brique contient un bonus
        */
        bool bonus;

        /**
         * @brief Indique le type de bonus de la brique
        */
        string typeBonus;

        /**
         * @brief Couleur de la brique
        */
        Couleur coulBrique;

    public:
        /**
         * @brief Position de la brique
        */
        int posX, posY;

        /**
         * @brief Constructeur par défaut de la classe: initialise sa position, si il a un bonus,
         * son type de bonus et sa couleur.
        */
        Brique();

        /**
         * @brief Constructeur de la classe: initialise sa position, si il a un bonus,
         * son type de bonus et sa couleur.
         * @param x : Entier
         * @param y : Entier
         * @param det : Booléen
         * @param typeBon : Chaine de caractères
         * @param c : Couleur
        */
        Brique(unsigned int x, unsigned int y, bool det, string typeBon, Couleur c);

        /**
         * @brief Destructeur de la classe : Mise à jour de posX et posY à 0, détruit à false,
         * typeBonus à null, et couleur à noire. 
        */
        ~Brique();

        /**
         * @brief Accesseur de la position en x d'une brique
        */
        unsigned int getPosX() const;

        /**
         * @brief Accesseur de la position en y d'une brique
        */
        unsigned int getPosY() const;
};

#endif