#include "Terrain.h"
#include <cassert>

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

Terrain::Terrain() {
	dimX = 26;
	dimY = 20;
	for(unsigned int x = 0 ; x < dimX ; x++) {
		for(unsigned int y = 0 ; y < dimY ; y++) {
			ter[x][y] = terrain1[dimY-1-y][x];
		}
	}
}

bool Terrain::isValidPos(const unsigned int x, const unsigned int y) const {
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

