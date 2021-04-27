#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <chrono>


#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu () : jeu() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    /*if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;*/

	int dimx, dimy;
	dimx = jeu.getConstTerrain().getDimX();
	dimy = jeu.getConstTerrain().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_perso.loadFromFile("data/perso.png", renderer);
    im_in_perso.loadFromFile("data/perso.png", renderer);
    im_mur.loadFromFile("data/mur.png", renderer);
    im_brique.loadFromFile("data/brique.png", renderer);
    im_b1.loadFromFile("data/bombe.png", renderer);
    im_b2.loadFromFile("data/bombe.png", renderer);
    im_ter.loadFromFile("data/terrain.png", renderer);

    // FONTS
    /*font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    if (font == NULL)
        font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf",50);
    if (font == NULL) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl; 
            SDL_Quit(); 
            exit(1);
	}*/
	/*font_color.r = 50;font_color.g = 50;font_color.b = 255;
	font_im.setSurface(TTF_RenderText_Solid(font,"Bomberman",font_color));
	font_im.loadFromCurrentSurface(renderer);*/

    // SONS
    /*if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == NULL) 
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == NULL) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl; 
                SDL_Quit();
                exit(1);
        }
    }*/
}

sdlJeu::~sdlJeu () {
    //if (withSound) Mix_Quit();
    //TTF_CloseFont(font);
    //TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff () {
	//Remplir l'�cran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Terrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPerso(0);
    const Personnage& in_perso = jeu.getConstPerso(1);
    const Bombe& b1 = jeu.getConstBombe(0);
    const Bombe& b2 = jeu.getConstBombe(1);

    // Afficher le sprite du sol
    for (x = 0 ; x < ter.getDimX() ; ++x) {
        for (y = 0 ; y < ter.getDimY() ; ++y) {
            im_ter.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
        }
    }


    // Afficher les sprites des murs et des pastilles
	for (x=0 ; x < ter.getDimX() ; ++x)
		for (y=0 ; y < ter.getDimY() ; ++y)
			if (ter.getXY(x,y) == '#')
				im_mur.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
			else if (ter.getXY(x,y) == '.')
				im_brique.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);

	// Afficher le sprite des perso
	im_perso.draw(renderer, perso.getPosX() * TAILLE_SPRITE, perso.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    im_in_perso.draw(renderer, in_perso.getPosX() * TAILLE_SPRITE, in_perso.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    
    //im_b2.draw(renderer, b1.getPosX() * TAILLE_SPRITE, b1.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);

    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 270; positionTitre.y = 49; positionTitre.w = 100; positionTitre.h = 30;
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &positionTitre);

}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
    bool quit = false;
    // tant que ce n'est pas la fin ...
    auto t0 = chrono::system_clock::now();
    while (!quit) {
        // tant qu'il y a des evenements � traiter (cette boucle n'est pas bloquante)
        auto t1 = chrono::system_clock::now();
        jeu.getBombe(0).setTempsExplo((t1 - t0).count());
        if(jeu.getBombe(0).getTempsExplo() < 2){
            jeu.exploserBombe(jeu.getPerso(0), jeu.getTerrain(), jeu.getBombe(0));
        }

        while (SDL_PollEvent(&events)) {
            if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
                bool briqueExplosee = false;
                switch (events.key.keysym.sym) {
                    case SDLK_o:
                        briqueExplosee = jeu.actionClavier('b');    // car Y inverse
                        break;
                    case SDLK_l:
                        briqueExplosee = jeu.actionClavier('h');     // car Y inverse
                        break;
                    case SDLK_k:
                        briqueExplosee = jeu.actionClavier('g');
                        break;
                    case SDLK_m:
                        briqueExplosee = jeu.actionClavier('d');
                        break;
                    case SDLK_p:
                        briqueExplosee = jeu.actionClavier('n');
                        //im_b1.draw(renderer, jeu.b1.getPosX() * TAILLE_SPRITE, jeu.b1.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
                        break;
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 2e JOUEUR ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    case SDLK_DOWN:
                        briqueExplosee = jeu.actionClavier('v');    // car Y inverse
                        break;
                    case SDLK_UP:
                        briqueExplosee = jeu.actionClavier('j');     // car Y inverse
                        break;
                    case SDLK_LEFT:
                        briqueExplosee = jeu.actionClavier('f');
                        break;
                    case SDLK_RIGHT:
                        briqueExplosee = jeu.actionClavier('c');
                        break;
                    case SDLK_KP_ENTER:
                        briqueExplosee = jeu.actionClavier('u');
                        break;
                    case SDLK_ESCAPE:
                    case SDLK_q:
                        quit = true;
                        break;
                    default: break;
                }/*
                if ((withSound) && (briqueExplosee))
                    Mix_PlayChannel(-1,sound,0);*/
            }
        }

        // on affiche le jeu sur le buffer cach�
        sdlAff();

        // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
    }
}