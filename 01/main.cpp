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
	assert((p1) && (p2) && !(p3) && (p4));
}

void AllocBeforeTest() {
	Allocator OurAllocator;
	char* p = OurAllocator.alloc(200);
	OurAllocator.makeAllocator(1024);
	assert(!(p));
}

void NAllocatorsTest() {
	Allocator OurAllocator;
	OurAllocator.makeAllocator(1024);
	char* p1 = OurAllocator.adress();
	OurAllocator.makeAllocator(1024);
	char* p2 = OurAllocator.adress();
	char* p = OurAllocator.alloc(1024);
	assert((p1 == p2) && p);
}

void BorderTest() {
	Allocator OurAllocator;
	OurAllocator.makeAllocator(10);
	char* p1 = OurAllocator.alloc(10);
	char* p2 = OurAllocator.alloc(1);
	OurAllocator.reset();
	char* p3 = OurAllocator.alloc(10);
	assert(p1 && !p2 && p3);
}

int main() {
	std::cout << "starting tests\n";
    GeneralTest();
	AllocBeforeTest();
	NAllocatorsTest();
	BorderTest();
	std::cout << "all tests passed\n";
	return 0;
}