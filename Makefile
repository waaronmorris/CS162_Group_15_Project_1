<<<<<<< HEAD
TARGET := Doodlebug_Group_Project
CFLAGS := -std=c++11
HEADERS := $(wildcard *.hpp)
SRC := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRC))

all: $(TARGET)

valgrind:
	valgrind./Doodlebug_Group_Project

clean:
	rm -f $(OBJS)
	rm -f $(TARGET)

%.o: %.cpp $(HEADERS)
	g++ $(CFLAGS) $< -c -o $@

$(TARGET): $(OBJS) | $(HEADERS)
	G++ $(cflags) $^ -O $@
=======
 CC:=g++ -std=c++11

sim: main.o Critter.o Ant.o Doodlebug.o Board.o Space.o
	$(CC) main.o Critter.o Ant.o DoodleBug.o Board.o Space.o -o sim

main.o: main.cpp
	$(CC) -c main.cpp

Critter.o: Critter.cpp Critter.h
	$(CC) -c Critter.cpp

Ant.o: Ant.cpp Ant.h
	$(CC) -c Ant.cpp

Doodlebug.o: DoodleBug.cpp DoodleBug.h
	$(CC) -c DoodleBug.cpp

Board.o: Board.cpp Board.h
	$(CC) -c Board.cpp

Space.o: Space.cpp Space.h
	$(CC) -c Space.cpp



clean:
	rm *.o sim

>>>>>>> 37572b50b943df1d58b254d35c1649e57240cb8f
