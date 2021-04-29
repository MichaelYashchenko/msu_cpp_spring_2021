#include "format.hpp"

void GeneralTest() {
	std::string str = format("abcd {} {}.", 1,"abcd", 1);
	assert(str == "abcd 1 abcd.");
	std::cout << "GeneralTest passed\n";
}

void EmptyStringTest() {
	std::string str = format("");
	assert(str == "");
	std::cout << "EmptyStringTest passed\n";
}

void NumberReplaceTest() {
	std::string str = format("abcd {3} {1}.", 1, "abcd", 1, 4);
	assert(str == "abcd 4 abcd.");
	std::cout << "NumberReplaceTest passed.\n"; 
}

int main() {
    std::cout << "Tests started\n";
    GeneralTest();
    EmptyStringTest();
    NumberReplaceTest();
    std::cout << "All tests successfully passed\n"; 
    return 0;
}