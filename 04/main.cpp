#include "BigInt.h"

void Tests() {
    BigInt a("10999999999999999999999999");
    BigInt b("30001023123421345423542353");
    BigInt c = -b;
    BigInt t(-1);
    BigInt zero(0);
    std::cout << "Starting tests:";
    std:: cout << "\nshould be 0, got " << zero;
    std::cout << "\nshould be 0, got " << b + c;
    std::cout << "\nshould be -19001023123421345423542354, got " << a - b;
    c = 500;
    t = -400;
    BigInt p(500);
    std::cout << "\nshould be 100, got " << t + c;
    assert(c >= t);
    assert(t != c);
    assert(c == p);
    assert(t <= c);
    assert(t < c);
    assert(c > t);
    std::cout << "\nTests are over, check if all is correct\n";
}


int main() {
    Tests();
    return 0;
}