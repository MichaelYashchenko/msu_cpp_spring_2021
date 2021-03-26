#include <iostream>
#include <cassert>
#include "Allocator.h"

void GeneralTest() {
	Allocator OurAllocator;
	OurAllocator.makeAllocator(1024);
	char* p1 = OurAllocator.alloc(200);
	char* p2 = OurAllocator.alloc(500);
	char* p3 = OurAllocator.alloc(500);
	OurAllocator.reset();
	char* p4 = OurAllocator.alloc(500);
	if ((p1) && (p2) && !(p3) && (p4)) {
		std::cout << "General test: correct\n";
	}
	else {
		std::cout << "General test: mistake\n";
	}
}

void AllocBeforeTest() {
	Allocator OurAllocator;
	char* p = OurAllocator.alloc(200);
	OurAllocator.makeAllocator(1024);
	if(!(p)) {
		std::cout << "AllocBefore test: correct\n";
	}
	else {
		std::cout << "AllocBefore test: mistake\n";
	}
}

void NAllocatorsTest() {
	Allocator OurAllocator;
	OurAllocator.makeAllocator(1024);
	char* p1 = OurAllocator.adress();
	OurAllocator.makeAllocator(1024);
	char* p2 = OurAllocator.adress();
	if(p1 == p2) {
		std::cout << "NAllocators test: correct\n";
	}
	else {
		std::cout << "NAllocators test: mistake\n";
	}	
}

int main() {
	std::cout << "starting tests:\n";
    GeneralTest();
	AllocBeforeTest();
	NAllocatorsTest();
	std::cout << "all tests passed:\n";
	return 0;
}