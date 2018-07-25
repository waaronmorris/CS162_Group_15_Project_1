 CC:=g++ -std=c++11

langston: main.o Board.o Ant.o Space.o utility.o
	$(CC) main.o Board.o Ant.o Space.o utility.o -o langston

main.o: main.cpp
	$(CC) -c main.cpp

utility.o: utility.cpp utility.h
	$(CC) -c utility.cpp

Board.o: Board.cpp Board.h
	$(CC) -c Board.cpp

Ant.o: Ant.cpp Ant.h
	$(CC) -c Ant.cpp

Space.o: Space.cpp Space.h
	$(CC) -c Space.cpp

clean:
	rm *.o langston

