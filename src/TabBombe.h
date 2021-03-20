/**
  @brief Module gérant un tableau de Bombe
  @file TabBombe.h

  @date 09/03/2021
*/

#ifndef TABBOMBE_H
#define TABBOMBE_H

#include "Bombe.h"
#include <vector>
using namespace std;

class TabBombe {
    private:

    /**
      * @brief
      * Tableau de taille variable de brique
    */
    vector<Bombe> tabBombe;
    unsigned int nbBombe;

    public:
    TabBombe();
    ~TabBombe();
    unsigned int getNbBombe() const;
    void setNbBombe(unsigned int nouvNbBombe);
    void testRegression();
};

#endif