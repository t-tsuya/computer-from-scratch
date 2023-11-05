CXX = g++ -std=c++17
CXXFLAGS = -Wall -g
INCLUDE = -I.

BIN = ./bin
SRC = ./src
OBJ = ./obj

OBJ_TEST = $(OBJ)/test.o
OBJS = $(OBJ)/gate.o $(OBJ_TEST)

.PHONY: all clean

all:  # execute this Makefile by "make" or "make all"
	make test

test: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(BIN)/$@ $(OBJS)

$(OBJ)/%.o: $(SRC)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:  # remove created files
	rm -rf $(OBJ) $(BIN)