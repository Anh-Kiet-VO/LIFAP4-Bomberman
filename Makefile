CC = g++
FLAGS = -c -ggdb -Wall

all: ./obj/Couleur.o ./obj/Personnage.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o

./obj/Couleur.o: ./src/Couleur.cpp ./src/Couleur.h
	$(CC) $(FLAGS) ./src/Couleur.cpp -o ./obj/Couleur.o

./obj/Personnage.o: ./src/Personnage.cpp ./src/Personnage.h
	$(CC) $(FLAGS) ./src/Personnage.cpp -o ./obj/Personnage.o

./obj/Brique.o: ./src/Brique.cpp ./src/Brique.h
	$(CC) $(FLAGS) ./src/Brique.cpp -o ./obj/Brique.o

./obj/TabBrique.o: ./src/TabBrique.cpp ./src/TabBrique.h
	$(CC) $(FLAGS) ./src/TabBrique.cpp -o ./obj/TabBrique.o

./obj/Bombe.o: ./src/Bombe.cpp ./src/Bombe.h
	$(CC) $(FLAGS) ./src/Bombe.cpp -o ./obj/Bombe.o

./obj/TabBombe.o: ./src/TabBombe.cpp ./src/TabBombe.h
	$(CC) $(FLAGS) ./src/TabBombe.cpp -o ./obj/TabBombe.o

doc:
	doxygen -g doc/image.doxy

clean:
	rm ./obj/*.o ./bin/*