#include  "allocator.hpp"
#include "iterator.hpp"
#include "vector.hpp"
#include "includes.hpp"

void ResizeTest() {
    vector<int> vec(10, -1);
    vec.resize(2, 3);
    assert(vec[0] == -1);
}

void EmtpyVecTest() {
    vector<int> vec(10, -1);
    vec.resize(0);
    assert(vec.empty());
    int a = 5;
    vec.push_back(a);
    assert(vec[0] == 5);
    vec.clear();
    assert(vec.empty());
}

void SizeTest() {
    vector<int> vec(10, -1);
    vec.resize(5, 1);
    assert(vec.size() == 5);
}

void IteratorTest() {
    vector<int> vec(5, 1);
    vec[2] = 2;
    auto it = vec.begin();
    assert(*(it + 2) == 2);
    it = vec.end();
    assert(*(it - 1) == 1);
}

int main() {
    std::cout << "Starting tests\n";
    ResizeTest();
    EmtpyVecTest();
    SizeTest();
    IteratorTest();
    std::cout << "All tests passed\n";
    return 0;
}