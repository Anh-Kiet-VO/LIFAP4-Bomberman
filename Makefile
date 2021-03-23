CC = g++
FLAGS = -ggdb -Wall

CORE = ./src/Terrain.cpp ./src/Jeu.cpp ./src/Personnage.cpp ./src/TabBrique.cpp ./src/TabBombe.cpp

SRCS_TXT = $(CORE) txt/JeuModeTexte.cpp txt/winTxt.cpp txt/main_txt.cpp

LIB = -I/src -Ilib

all: ./bin/Test ./bin/mainTXT

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

# ----------------------------------------------------- #

./obj/JeuModeTexte.o: ./txt/JeuModeTexte.cpp ./txt/JeuModeTexte.h ./txt/txtWin.h
	$(CC) $(FLAGS) -c ./txt/JeuModeTexte.cpp $(LIB) -o ./obj/JeuModeTexte.o

./obj/winTxt.o: ./txt/winTxt.cpp ./txt/winTxt.h
	$(CC) $(FLAGS) -c ./txt/winTxt.cpp -o ./obj/winTxt.o

./bin/mainTXT: ./txt/main_txt.o ./txt/txtWin.o ./txt/JeuModeTexte.o
	$(CC) $(FLAGS) -c ./obj/main_txt.o ./obj/txtWin.o ./obj/JeuModeTexte.o

./obj/main_txt.o: ./txt/main_txt.cpp ./txt/txtWin.h ./txt/JeuModeTexte.h
	$(CC) $(FLAGS) -c ./txt/main_txt.cpp $(LIB) -o ./obj/main_txt.o

# ----------------------------------------------------- #

#$(CORE) $(SRCS_TXT:%.cpp=obj/%.o)
	#$(CC) $(FLAGS) $+ -o $@ $(LDFLAGS)

doc:
	doxygen -g doc/image.doxy

clean:
ifeq ($(OS), Windows_NT)
	del .\obj\*.o
	del .\bin\*.exe
else
	rm ./obj/*.o ./bin/*.exe
endif