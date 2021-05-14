CC=clang++ 
FLAGS=-std=c++17
  
all: run

test: main.cpp threadpool.cpp
	$(CC) $(FLAGS) -o test main.cpp -lpthread
 
run: test  
	./test