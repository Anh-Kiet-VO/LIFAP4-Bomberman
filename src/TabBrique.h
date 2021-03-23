/**
  @brief Module gérant un tableau de Brique
  @file TabBrique.h

  @date 9 mars 2021
*/      

#ifndef TABBRIQUE_H
#define TABBRIQUE_H

#include "Couleur.h"
#include "Brique.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class TabBrique{
    private:

        /**
         * @brief
         * Tableau de taille variable de brique
        */
        vector<Brique> tabBrique;
        
        /**
         * @brief
         * Le nombre de briques
        */
        unsigned int nbBrique;
    
    public:
        /**
         * @brief
         * Constructeur par défaut de la classe: initialise un tableau
         * par défaut et un nombre de briques par défaut.
        */
        TabBrique();
        
        /**
         * @brief
         * Destructeur de la classe :
        */
        ~TabBrique();

        /**
         * @brief
         * Accesseur du nombre de briques
        */
        unsigned int getNbBrique();

        /**
         * @brief
         * Mutateur de nombre de briques
        */
        void setNbBrique(unsigned int nouvNbBrique);

        /**
         * @brief
         * Accesseur de l'état d'une brique
        */
        bool getDetruit(unsigned int bri);

        /**
         * @brief
         * Mutateur de l'état d'une brique
        */
        void setDetruit(unsigned int bri, bool det);

        /**
         * @brief
         * Accesseur d'une brique
        */
        Brique getBrique(int i);

        /**
         * @brief
         * Test de regression
        */
        void testRegression();
};

#endif