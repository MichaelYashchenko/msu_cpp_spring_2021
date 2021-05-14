#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <cassert>

class BigInt {
private:
	char *num;
	bool minus;


	bool smaller(const char* a, const char* b) const;
	BigInt sum(const BigInt& a, const BigInt& b) const;
	BigInt subtract(const BigInt& a, const BigInt& b) const;
	BigInt multiply(const BigInt& a, const BigInt& b) const;
	char digit2char(int x) const;
	int char2digit(char x) const;
public:
	BigInt();
	BigInt(int number);
	BigInt(const char* number);
	~BigInt();

	BigInt(const BigInt& a);
	BigInt(BigInt&& a);
	BigInt& operator=(const BigInt& a);
	BigInt& operator=(BigInt&& a);

	BigInt operator+(const BigInt& a) const;
	BigInt operator+(const int a) const;
	BigInt operator-() const;
	BigInt operator-(const BigInt& a) const;
	BigInt operator-(const int a) const;
	BigInt operator*(const BigInt& a) const;
	BigInt operator*(const int a) const;

	bool operator==(const BigInt& a) const;
	bool operator!=(const BigInt& a) const;
	bool operator>(const BigInt& a) const;
	bool operator>=(const BigInt& a) const;
	bool operator<(const BigInt& a) const;
	bool operator<=(const BigInt& a) const;

	char* NumToStr() const;

	friend std::ostream& operator<<(std::ostream& oss, const BigInt& a);
};