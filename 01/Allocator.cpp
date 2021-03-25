#include <cstdlib>
#include "Allocator.h"

void Allocator::makeAllocator(size_t max_Size) {
	start = (char*) std::malloc(max_Size);
	if (start == NULL) {
		throw "Error";
	}
	else {
		right = start;
		num_bites = max_Size;
	}
}

char* Allocator::alloc(size_t size) {
	if (right + size > start + num_bites - 1) {
		return nullptr;
	}
	right += size;
	char* tmp = right - size_t(size);
	return tmp;
}

void Allocator::reset(void) {
	right = start;
}