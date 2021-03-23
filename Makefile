CC = g++
FLAGS = -ggdb -Wall

CORE = ./src/Terrain.cpp ./src/Jeu.cpp ./src/Personnage.cpp ./src/TabBrique.cpp ./src/TabBombe.cpp

SRCS_TXT = $(CORE) txt/JeuModeTexte.cpp txt/winTxt.cpp txt/main_txt.cpp

all: ./bin/Test

./bin/Test: ./obj/Test.o ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/Terrain.o
	$(CC) $(FLAGS) ./obj/Test.o ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/Terrain.o -o ./bin/Test

./obj/Test.o: ./src/Test.cpp ./src/Couleur.h ./src/Brique.h ./src/TabBrique.h ./src/Bombe.h ./src/TabBombe.h
	$(CC) $(FLAGS) -c ./src/Test.cpp -o ./obj/Test.o

# ----------------------------------------------------- #

./obj/Couleur.o: ./src/Couleur.cpp ./src/Couleur.h
	$(CC) $(FLAGS) -c ./src/Couleur.cpp -o ./obj/Couleur.o

./obj/Personnage.o: ./src/Personnage.cpp ./src/Personnage.h
	$(CC) $(FLAGS) -c ./src/Personnage.cpp -o ./obj/Personnage.o

./obj/Brique.o: ./src/Brique.cpp ./src/Brique.h
	$(CC) $(FLAGS) -c ./src/Brique.cpp -o ./obj/Brique.o

./obj/TabBrique.o: ./src/TabBrique.cpp ./src/TabBrique.h
	$(CC) $(FLAGS) -c ./src/TabBrique.cpp -o ./obj/TabBrique.o

./obj/Bombe.o: ./src/Bombe.cpp ./src/Bombe.h
	$(CC) $(FLAGS) -c ./src/Bombe.cpp -o ./obj/Bombe.o

./obj/TabBombe.o: ./src/TabBombe.cpp ./src/TabBombe.h
	$(CC) $(FLAGS) -c ./src/TabBombe.cpp -o ./obj/TabBombe.o

./obj/Terrain.o: ./src/Terrain.cpp ./src/Terrain.h
	$(CC) $(FLAGS) -c ./src/Terrain.cpp -o ./obj/Terrain.o

doc:
	doxygen -g doc/image.doxy

clean:
ifeq ($(OS), Windows_NT)
	del .\obj\*.o
	del .\bin\*.exe
else
	rm ./obj/*.o ./bin/*.exe
endif