### Adapted make file from: 
### 	@author - Harlan James <waldroha@oregonstate.edu
### Author: Tres Oelze
### Date: 7.26.18

PROJ = Doodlebug

$(CXX) = g++ -std=c++11

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

