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
		size_t getRows();
		size_t getCols();
		Matrix& operator*= (int k);
	    friend const Matrix operator+ (const Matrix& m1, const Matrix& m2);
		const bool operator== (const Matrix& m);
		const bool operator!= (const Matrix& m);
		Proxy operator[] (size_t i) const;
	    friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
		~Matrix();
};