/**
  @brief Module gérant un tableau de Bombe
  @file TabBombe.h

  @date 09/03/2021
*/

#ifndef TABBOMBE_H
#define TABBOMBE_H

#include "Bombe.h"
#include <vector>

class TabBombe {
    private:
    unsigned int nbBombe;

    public:
    TabBombe();
    ~TabBombe();
    unsigned int getNbBombe() const;
    void setNbBombe(unsigned int nouvNbBombe);
    void testRegression();
};

#endif