VAR0 = 0
VAR1 = 1
#...
#...
#...
CPP = g++
SRC = a.cpp
LIB = -fopenmp
INC = 

all:	build	clean	run
	echo 'all'
	echo $(VAR0)
build:
	echo 'build'
	#	g++ a.cpp -fopenmp
	$(CPP) $(SRC) $(LIB) 
clean:
	echo 'clean'
run:
	echo 'run'
	./a.out

