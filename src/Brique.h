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
<<<<<<< HEAD
         * @brief Le booléen pour indiquer si la brique contient un bonus
=======
         * @brief Booléen pour indiquer si la brique est détruite
        */
        bool detruit;

        /**
         * @brief Booléen pour indiquer si la brique contient un bonus
>>>>>>> d831c3508f4656973865b546f7e572f032c31d47
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
         * @brief Le booléen pour indiquer si la brique est détruite
        */
        bool detruit;

        /**
<<<<<<< HEAD
         * @brief Constructeur par défaut de la classe: initialise sa position, si il a un bonus,
         * son type de bonus et sa couleur.
=======
         * @brief Constructeur par défaut de la classe : initialise sa position, si il a un bonus, son type de bonus et sa couleur
>>>>>>> d831c3508f4656973865b546f7e572f032c31d47
        */
        Brique();

        /**
<<<<<<< HEAD
         * @brief Constructeur de la classe: initialise sa position, si il a un bonus,
         * son type de bonus et sa couleur.
         * @param x : Entier
         * @param y : Entier
         * @param det : Booléen
         * @param typeBon : Chaine de caractères
         * @param c : Couleur
=======
         * @brief Constructeur de la classe : initialise sa position, si il a un bonus, son type de bonus et sa couleur
         @param x : entier
         @param y : entier
         @param det : booléen
         @param typeBon : chaîne de caractères
         @param c : Couleur
>>>>>>> d831c3508f4656973865b546f7e572f032c31d47
        */
        Brique(unsigned int x, unsigned int y, bool det, string typeBon, Couleur c);

        /**
         * @brief Destructeur de la classe : mise à jour de posX et posY à 0, détruit à false, typeBonus à NULL, et couleur à noir
        */
        ~Brique();

        /**
         * @brief Accesseur de la position en X d'une brique
        */
        unsigned int getPosX() const;

        /**
         * @brief Accesseur de la position en X d'une brique
        */
        unsigned int getPosY() const;
};

#endif