#include "winTxt.h"
#include "JeuModeTexte.h"

int main ( int argc, char** argv ) {
    termClear();
	Jeu jeu;
	txtBoucle(jeu);
    termClear();
	return 0;
}