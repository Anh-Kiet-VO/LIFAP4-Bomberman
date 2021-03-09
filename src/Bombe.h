#ifndef BOMBE_H
#define BOMBE_H

class Bombe {
    private:
    unsigned int posX, posY;
    unsigned int portee;

    public:
    Bombe();
    Bombe(unsigned int positionX, unsigned int positionY, unsigned int porteeBombe);
    ~Bombe();

    unsigned int getPosX() const;
    unsigned int getPosY() const;
    unsigned int getPortee() const;
    void setPortee(unsigned int p);
};

#endif