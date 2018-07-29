<<<<<<< HEAD
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
=======
### Adapted make file from: 
### 	@author - Harlan James <waldroha@oregonstate.edu
### Author: Tres Oelze
### Date: 7.26.18

PROJ = Doodlebug

$(CXX) = g++

SRC = main.cpp
SRC += Ant.cpp
SRC += Board.cpp
SRC += Critter.cpp
SRC += DoodleBug.cpp
SRC += menu.cpp
SRC += menu_item.cpp
SRC += my_lib.cpp
SRC += Space.cpp

OBJ = $(SRC:.cpp=.o)

BIN = $(PROJ).bin

CFLAGS = -Wall -pedantic -std=gnu++11

VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

.PHONY: default debug clean zip

default: clean $(BIN) debug

debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

zip: 
	zip $(PROJ).zip *.cpp *.hpp makefile

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BIN)"
	@rm -f *.o $(BIN)

>>>>>>> d8e20ade9b3d20b57cdc2e0c89210287cafaa26e
