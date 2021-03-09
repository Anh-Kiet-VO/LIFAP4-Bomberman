#ifndef IMAGE_H
#define IMAGE_H

#include "Couleur.h"

#include <string>
class Brique{
    private:
        bool détruit;
        bool bonus;
        string typeBonus;
        Couleur coolBrique;

    public:
        int posX, posY;

        Brique();

        Brique(int x, int y, bool det, bool typeBon, Couleur coul);

        ~Brique();

        int getPosX();
        int getPosY();
}