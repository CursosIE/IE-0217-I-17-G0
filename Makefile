COMPILER = g++
SRC = matrizfinal.cpp
FLAGS = -W -Wall -o
BIN = matriz
LIB =
INC =

all:	build	clean	run

build:
	#	g++ a.cpp -fopenmp
	$(COMPILER) $(SRC) $(FLAGS) $(BIN)
clean:
run:
	./$(BIN)
