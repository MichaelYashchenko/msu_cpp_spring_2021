CC=clang++ 
FLAGS=-std=c++17
  
all: run

test: main.cpp iterator.hpp allocator.hpp vector.hpp includes.hpp
	$(CC) $(FLAGS) -o test main.cpp
 
run: test  
	./test