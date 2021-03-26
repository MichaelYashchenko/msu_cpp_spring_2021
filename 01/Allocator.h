#ifndef ALLOCATOR_H
#define ALLOCATOR_H

class Allocator{
private:
    char* right;
    char* start;
    size_t num_bites;
public:
    Allocator(): start(nullptr), right(nullptr), num_bites(size_t(0)) {};
    void makeAllocator(size_t maxSize);
    char* adress();
    char* alloc(size_t size);
    void reset(void);
    ~Allocator();
};

#endif