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
	const Personnage& perso = jeu.getConstPerso();
	const Bombe& b = jeu.getConstBombe();

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
	//win.print(perso.getPosX(), perso.getPosY(), 'P');

	win.print(b.getPosX(), b.getPosY(), 'o');
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
			case 'q':
				ok = false;
				break;
		}
	} while (ok);
}
