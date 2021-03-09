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
<<<<<<< HEAD
         * @brief
         * Constructeur par défaut de la classe: initialise sa position par défaut, son bonus par défaut,
=======
         * @brief Constructeur par défaut de la classe: initialise sa position, si il a un bonus,
>>>>>>> 9d079b479f0d74a232082a15f5db1bb0a942796b
         * son type de bonus et sa couleur.
        */
        Brique();

        /**
         * @brief Constructeur de la classe: initialise sa position, si il a un bonus,
         * son type de bonus et sa couleur.
<<<<<<< HEAD
         @param x : entier
         @param y : entier
         @param det : booléen
         @param typeBon : chaine de caractères
         @param c : Couleur
=======
         * @param x : Entier
         * @param y : Entier
         * @param det : Booléen
         * @param typeBon : Chaine de caractères
         * @param c : Couleur
>>>>>>> 9d079b479f0d74a232082a15f5db1bb0a942796b
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