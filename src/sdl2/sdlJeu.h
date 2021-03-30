#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "Jeu.h"

//! \brief Pour grer une image avec SDL2
class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;

public:
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};

class sdlJeu {

private :

	Jeu jeu;

    SDL_Window * window;
    SDL_Renderer * renderer;

    TTF_Font * font;
    Image font_im;
    SDL_Color font_color;

    Mix_Chunk * sound;
    bool withSound;

    Image im_perso;
    Image im_brique;
    Image im_bombe;
    Image im_mur;

    bool souris;
    bool touche;
public :

    sdlJeu ();
    ~sdlJeu ();
    void sdlBoucle ();
    void sdlAff ();

};

#endif
