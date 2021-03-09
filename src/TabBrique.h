/**
  @brief Module gérant un tableau de Brique
  @file Brique.h

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
        //vector<Brique> tabBrique;
        
        /**
         * @brief
         * Le nombre de briques
        */
        unsigned int nbBrique;
    
    public:
        /**
         * @brief
         * Le nombre de briques
        */
        TabBrique();

        /**
         * @brief
         * Le nombre de briques
        */
        TabBrique();

        /**
         * @brief
         * Le nombre de briques
        */
        ~TabBrique();

        /**
         * @brief
         * Le nombre de briques
        */
        unsigned int getNbBrique();

        /**
         * @brief
         * Le nombre de briques
        */
        unsigned int getDetruit();

        /**
         * @brief
         * Le nombre de briques
        */
        void setDetruit(unsigned int bri, bool det);

        /**
         * @brief
         * Le nombre de briques
        */
        Brique getBrique(unsigned int nbBrique);

        /**
         * @brief
         * Le nombre de briques
        */
        void testRegression();
};

#endif