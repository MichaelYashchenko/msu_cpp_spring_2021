#pragma once
#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include <sstream>

class Matrix {
	size_t rows = 0;
	size_t cols = 0;
	int** arr = nullptr;
	public:
		class Proxy {
			public:
			size_t size = 0; //j
			int* data = nullptr; //i
			Proxy(int* d, size_t s);
			int& operator[] (size_t i) const;

		};
		Matrix(size_t r, size_t c);
		size_t getRows() const;
		size_t getCols() const;
		Matrix& operator*= (int k);
		Matrix operator+ (const Matrix& m) const;
		const bool operator== (const Matrix& m) const;
		const bool operator!= (const Matrix& m) const;
		Proxy operator[] (size_t i) const;
	    friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
		~Matrix();
};