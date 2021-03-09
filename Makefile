CC = g++
FLAGS = -c -ggdb -Wall

all: ./obj/Couleur.o ./obj/Personnage.o ./obj/Bombe.o ./obj/Brique.o

./obj/Couleur.o: ./src/Couleur.cpp ./src/Couleur.h
	$(CC) $(FLAGS) ./src/Couleur.cpp -o ./obj/Couleur.o

./obj/Personnage.o: ./src/Personnage.cpp ./src/Personnage.h
	$(CC) $(FLAGS) ./src/Personnage.cpp -o ./obj/Personnage.o

./obj/Brique.o: ./src/Brique.cpp ./src/Brique.h
	$(CC) $(FLAGS) ./src/Brique.cpp -o ./obj/Brique.o

./obj/Bombe.o: ./src/Bombe.cpp ./src/Bombe.h
	$(CC) $(FLAGS) ./src/Bombe.cpp -o ./obj/Bombe.o

doc:
	doxygen -g doc/image.doxy

clean:
	rm ./obj/*.o ./bin/*