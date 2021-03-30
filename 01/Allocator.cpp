#include <cstdlib>
#include "Allocator.h"

void Allocator::makeAllocator(size_t max_Size) {
	delete[] start;
	start = new char[max_Size];
	if (start ==  nullptr) {
		throw "Error";
	}
	else {
		right = start;
		num_bites = max_Size;
	}
}

char* Allocator::adress() {
	return this->start;
}

char* Allocator::alloc(size_t size) {
	if (right + size > start + num_bites) {
		return nullptr;
	}
	right += size;
	char* tmp = right - size;
	return tmp;
}

void Allocator::reset(void) {
	right = start;
}

Allocator::~Allocator() {
	delete[] start;
}