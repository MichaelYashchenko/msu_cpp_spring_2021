CC=clang++
FLAGS=-std=c++17


all: main.o parser.o
	$(CC) $(FLAGS) main.o parser.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

parser.o: parser.cpp
	$(CC) $(FLAGS) parser.cpp -c

test: main.o parser.o
	$(CC) $(FLAGS) main.o parser.o -o test
	./test	
	

clean:
	rm -rf *.o main