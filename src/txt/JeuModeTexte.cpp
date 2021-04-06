#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include <iostream>
#include "JeuModeTexte.h"
//#include "../src/Jeu.h"
//#include "winTxt.h"

void txtAff(WinTXT & win, const Jeu & jeu){
	const Terrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPerso(0);
	const Personnage& in_perso = jeu.getConstPerso(1);
	//const Bombe& b = jeu.getConstBombe();

	win.clear();

    // Affichage des murs et des pastilles
	for(int x = 0 ; x < ter.getDimX() ; x++) {
		for(int y = 0 ; y < ter.getDimY() ; y++) {
			win.print(x, y, ter.getXY(x,y));
		}
	}

    // Affichage du joueur 1
	win.print(perso.getPosX(), perso.getPosY(), 'B');
	// Affichage du joueur 2
	win.print(in_perso.getPosX(), in_perso.getPosY(), 'P');
	win.draw();
}

void txtBoucle(Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(), jeu.getConstTerrain().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		c = win.getCh();
		switch (c) {
			case 'k':
				jeu.actionClavier('g');
				break;
			case 'm':
				jeu.actionClavier('d');
				break;
			case 'l':
				jeu.actionClavier('h');
				break;	
			case 'o':
				jeu.actionClavier('b');
				break;
			case 'p':
				jeu.actionClavier('n');
				break;
			case 'c':
				ok = false;
				break;
		// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 2e JOUEUR ICI !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            case 's':
                jeu.actionClavier('v');    // car Y inverse
                break;
            case 'z':
	            jeu.actionClavier('j');     // car Y inverse
                break;
            case 'q':
                jeu.actionClavier('f');
                break;
            case 'd':
                jeu.actionClavier('c');
                break;
            case 'a':
                jeu.actionClavier('u');
                break;
		}
	} while (ok);
}
