CC=clang++
FLAGS=-std=c++17


all: main.o matrix.o
	$(CC) $(FLAGS) main.o matrix.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

matrix.o: matrix.cpp
	$(CC) $(FLAGS) matrix.cpp -c

test: main.o matrix.o
	$(CC) $(FLAGS) main.o matrix.o -o test
	./test	
	

clean:
	rm -rf *.o main
	