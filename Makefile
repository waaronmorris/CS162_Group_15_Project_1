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
