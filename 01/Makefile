CC=clang++
FLAGS=-std=c++17


all: main.o Allocator.o
	$(CC) $(FLAGS) main.o Allocator.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

Allocator.o: Allocator.cpp 
	$(CC) $(FLAGS) Allocator.cpp -c

test: main.o Allocator.o
	$(CC) $(FLAGS) main.o Allocator.o -o test
	./test	
	

clean:
	rm -rf *.o main
	