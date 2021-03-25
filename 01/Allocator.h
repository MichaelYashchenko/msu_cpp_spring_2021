#ifndef ALLOCATOR_H
#define ALLOCATOR_H

class Allocator{
private:
    char* right;
    char* start;
    size_t num_bites;
public:
    void makeAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset(void);
};

#endif