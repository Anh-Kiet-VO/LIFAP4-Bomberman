#include "Terrain.h"
#include <cassert>

using namespace std;
#include <iostream>

#include <windows.h>


const char terrain1[20][27] = {
"##########################",
"#  $$$$$#$$$$$#$$$$$#$$  #",
"# $$$$$$$$$$$$$$$$$$$$$$ #",
"#$$$$$$$#$$$$$#$$$$$#$$$$#",
"#$$$$$$$$$$$$$$$$$$$$$$$$#",
"#$$$$$$$#$$$$$#$$$$$#$$$$#",
"#$$$$$$$$$$$$$$$$$$$$$$$$#",
"#$$$$$$$#$$$$$#$$$$$#$$$$#",
"#$$$$$$$$$$$$$$$$$$$$$$$$#",
"# $$$$$$#$$$$$#$$$$$#$$$ #",
"#  $$$$$$$$$$$$$$$$$$$$  #",
"##########################"
};

const char terrain2[20][27] = {
"##########################",
"#  .....#.....#.....#..  #",
"# ...................... #",
"#.......#.....#.....#....#",
"#........................#",
"#.......#.....#.....#....#",
"#........................#",
"#.......#.....#.....#....#",
"#........................#",
"# ......#.....#.....#... #",
"#  ....................  #",
"##########################"
};

#ifdef _WIN32
void Terrain::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO	cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; 
    SetConsoleCursorInfo(out, &cursorInfo);
}
#endif 

Terrain::Terrain() {
	dimX = 26;
	dimY = 20;
	
	ShowConsoleCursor(false);
	for(unsigned int x = 0 ; x < dimX ; x++) {
		for(unsigned int y = 0 ; y < dimY ; y++) {
			ter[x][y] = terrain2[dimY-1-y][x];
		}
	}
}


bool Terrain::estPosValid(const unsigned int x, const unsigned int y) const {
	return ( (x >= 0) && (x < dimX) && (y >= 0) && (y < dimY) && (ter[x][y] !='#') );
}

char Terrain::getXY(const unsigned int x, const unsigned int y) const {
	assert(x >= 0);
	assert(y >= 0);
	assert(x < dimX);
	assert(y < dimY);

	return ter[x][y];
}

int Terrain::getDimX () const {
	return dimX;
}

int Terrain::getDimY () const {
	return dimY;
}

