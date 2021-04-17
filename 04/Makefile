CC=clang++
FLAGS=-std=c++17


all: main.o BigInt.o
	$(CC) $(FLAGS) main.o BigInt.o -o main

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp -c

BigInt.o: BigInt.cpp
	$(CC) $(FLAGS) BigInt.cpp -c

test: main.o BigInt.o
	$(CC) $(FLAGS) main.o BigInt.o -o test
	./test	
	

clean:
	rm -rf *.o main
	