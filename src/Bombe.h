/**
  @brief Module gérant une Bombe
  @file Bombe.h
  @date 09/03/2021
*/

#ifndef BOMBE_H
#define BOMBE_H

class Bombe {
    private:
    /**
     * @brief Position de la bombe
    */
    unsigned int posX, posY;

    /**
     * @brief Portée de la bombe
    */
    unsigned int portee;

    public:
    /**
     * @brief Constructeur par défaut de la classe : initialise la position à 0 et la portée à 0
    */
    Bombe();

    /**
     * @brief Constructeur de la classe : initialise la position avec positionX, positionY et la portée avec nouvPortee
     * @param positionX : unsigned int
     * @param positionY : unsigned int
     * @param nouvPortee : int 
    */
    Bombe(unsigned int positionX, unsigned int positionY, int nouvPortee);

    /**
     * @brief Destruction de la classe : met la position à 0 et la portée à 0
    */
    ~Bombe();

    /**
     * @brief Accesseur : récupère la position X de la bombe
    */
    unsigned int getPosX() const;

    /**
     * @brief Accesseur : récupère la position Y de la bombe
    */
    unsigned int getPosY() const;

    /**
     * @brief Accesseur : récupère la portée de la bombe
    */
    unsigned int getPortee() const;

    /**
     * @brief Mutateur : modifie la portée de la bombe
     * @param p : int
    */
    void setPortee(int p);
};

#endif