 CC:=g++ -std=c++11

sim: main.o Critter.o Ant.o Doodlebug.o Board.o Space.o
	$(CC) main.o Critter.o Ant.o Doodlebug.o Board.o Space.o -o sim

main.o: main.cpp
	$(CC) -c main.cpp

Critter.o: Critter.cpp Critter.h
	$(CC) -c Critter.cpp

Ant.o: Ant.cpp Ant.h
	$(CC) -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h
	$(CC) -c Doodlebug.cpp

Board.o: Board.cpp Board.h
	$(CC) -c Board.cpp

Space.o: Space.cpp Space.h
	$(CC) -c Space.cpp



clean:
	rm *.o sim

