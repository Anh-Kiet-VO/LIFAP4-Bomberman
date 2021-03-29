CC = g++
FLAGS = -ggdb -Wall

ALLOBJ= ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/Terrain.o ./obj/Jeu.o ./obj/TabPersonnage.o

CORE = ./src/Terrain.cpp ./src/Jeu.cpp ./src/Personnage.cpp ./src/TabBrique.cpp ./src/TabBombe.cpp ./src/TabPersonnage.cpp

SRCS_TXT = $(CORE) txt/JeuModeTexte.cpp txt/winTxt.cpp txt/main_txt.cpp

LIB = -Isrc/

all: ./bin/Test ./bin/mainTXT

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

doc:
	doxygen -g doc/image.doxy

clean:
ifeq ($(OS), Windows_NT)
	del .\obj\*.o
	del .\bin\*.exe
else
	rm ./obj/*.o ./bin/*.exe
endif
