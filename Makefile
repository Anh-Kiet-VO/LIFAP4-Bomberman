CC = g++
FLAGS = -ggdb -Wall

ALLOBJ= ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/Terrain.o ./obj/Jeu.o ./obj/TabPersonnage.o

CORE = ./src/Terrain.cpp ./src/Jeu.cpp ./src/Personnage.cpp ./src/TabBrique.cpp ./src/TabBombe.cpp ./src/TabPersonnage.cpp

SRCS_TXT = $(CORE) txt/JeuModeTexte.cpp txt/winTxt.cpp txt/main_txt.cpp

LIB = -Isrc/

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif

all: ./bin/Test ./bin/mainTXT ./bin/mainSDL

./bin/Test: ./obj/Test.o ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/Terrain.o ./obj/TabPersonnage.o
	$(CC) $(FLAGS) ./obj/Test.o ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/TabPersonnage.o ./obj/Terrain.o -o ./bin/Test.exe

./obj/Test.o: ./src/Test.cpp ./src/Couleur.h ./src/Brique.h ./src/TabBrique.h ./src/Bombe.h ./src/TabBombe.h  ./src/Personnage.h ./src/TabPersonnage.h
	$(CC) $(FLAGS) -c ./src/Test.cpp -o ./obj/Test.o

# ----------------------------------------------------- #

./obj/Couleur.o: ./src/Couleur.cpp ./src/Couleur.h
	$(CC) $(FLAGS) -c ./src/Couleur.cpp -o ./obj/Couleur.o

./obj/Personnage.o: ./src/Personnage.cpp ./src/Personnage.h ./src/Terrain.h ./src/TabBombe.h ./src/Couleur.h
	$(CC) $(FLAGS) -c ./src/Personnage.cpp -o ./obj/Personnage.o

./obj/TabPersonnage.o: ./src/TabPersonnage.cpp ./src/TabPersonnage.h ./src/Personnage.h
	$(CC) $(FLAGS) -c ./src/TabPersonnage.cpp -o ./obj/TabPersonnage.o

./obj/Brique.o: ./src/Brique.cpp ./src/Brique.h ./src/Couleur.h
	$(CC) $(FLAGS) -c ./src/Brique.cpp -o ./obj/Brique.o

./obj/TabBrique.o: ./src/TabBrique.cpp ./src/TabBrique.h ./src/Brique.h
	$(CC) $(FLAGS) -c ./src/TabBrique.cpp -o ./obj/TabBrique.o

./obj/Bombe.o: ./src/Bombe.cpp ./src/Bombe.h
	$(CC) $(FLAGS) -c ./src/Bombe.cpp -o ./obj/Bombe.o

./obj/TabBombe.o: ./src/TabBombe.cpp ./src/TabBombe.h ./src/Bombe.h
	$(CC) $(FLAGS) -c ./src/TabBombe.cpp -o ./obj/TabBombe.o

./obj/Terrain.o: ./src/Terrain.cpp ./src/Terrain.h
	$(CC) $(FLAGS) -c ./src/Terrain.cpp -o ./obj/Terrain.o

# ----------------------------------------------------- #

./bin/mainTXT: ./obj/main_txt.o ./obj/winTxt.o ./obj/JeuModeTexte.o $(ALLOBJ)
	$(CC) $(FLAGS) $(ALLOBJ) ./obj/main_txt.o ./obj/winTxt.o ./obj/JeuModeTexte.o -o ./bin/mainTXT

./obj/main_txt.o: ./txt/main_txt.cpp ./txt/winTxt.h ./txt/JeuModeTexte.h ./src/Jeu.h
	$(CC) $(FLAGS) -c ./txt/main_txt.cpp $(LIB) -o ./obj/main_txt.o

./obj/JeuModeTexte.o: ./txt/JeuModeTexte.cpp ./txt/JeuModeTexte.h ./txt/winTxt.h ./src/Jeu.h
	$(CC) $(FLAGS) -c ./txt/JeuModeTexte.cpp $(LIB) -o ./obj/JeuModeTexte.o

./obj/winTxt.o: ./txt/winTxt.cpp ./txt/winTxt.h
	$(CC) $(FLAGS) -c ./txt/winTxt.cpp -o ./obj/winTxt.o

./obj/Jeu.o: ./src/Jeu.cpp ./src/Jeu.h ./src/Personnage.h ./src/Terrain.h
	$(CC) $(FLAGS) -c ./src/Jeu.cpp -o ./obj/Jeu.o

# ----------------------------------------------------- #

ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = -Iextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2 \
			-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif

# ----------------------------------------------------- #

./bin/mainSDL: ./obj/main_SDL.o
	$(CC) $(FLAGS) $(INCLUDES_DIR_SDL) ./obj/main_SDL.o -o ./bin/mainSDL $(LIBS_SDL)

./obj/main_SDL.o: ./sdl/main_SDL.cpp
	$(CC) $(FLAGS) -c ./sdl/main_SDL.cpp -o ./obj/main_SDL.o

# ----------------------------------------------------- #
doc:
	doxygen -g doc/image.doxy

clean:
ifeq ($(OS), Windows_NT)
	del .\obj\*.o
	del .\bin\*.exe
else
	rm ./obj/*.o ./bin/*.exe
endif
