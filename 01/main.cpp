#include <iostream>
#include "Allocator.h"

void Test(){
	Allocator OurAllocator;
	OurAllocator.makeAllocator(1024);
	std::cout << "starting test:\n";
	char* p1 = OurAllocator.alloc(200);
	char* p2 = OurAllocator.alloc(500);
	char* p3 = OurAllocator.alloc(500);
	OurAllocator.reset();
	char* p4 = OurAllocator.alloc(500);
	if ((p1) && (p2) && !(p3) && (p4)) {
		std::cout << "correct\n";
	}
	else {
		std::cout << "mistake\n";
	}
}

int main() {
    Test();
	return 0;
}