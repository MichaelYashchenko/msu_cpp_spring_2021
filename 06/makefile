CC=clang++
FLAGS=-std=c++17

all: test  
 
main: main.cpp format.hpp 
	$(CC) $(FLAGS) -o main main.cpp

test: main
	./main

clean:
	rm -rf *.o main