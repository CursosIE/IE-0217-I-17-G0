COMPILER = g++
SRC = matrizfinal.cpp
FLAGS = -W -Wall -o
BIN = matriz
LIB =
INC =

all:	build	run clean

build:
	#	g++ a.cpp -fopenmp
	$(COMPILER) $(SRC) $(FLAGS) $(BIN)
run:
	./$(BIN)
clean:
	rm $(BIN)
