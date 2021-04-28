#include "matrix.h"

void SumTest() {
	const size_t rows = 3;
	const size_t cols = 5;
	Matrix m1(rows, cols);
	Matrix m2(rows, cols);
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			m1[i][j] = 1;
			m2[i][j] = 3;
		}
	}
	Matrix m3 = m1 + m2;
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			assert(m1[i][j] == 1);
			assert(m2[i][j] == 3);
			assert(m3[i][j] == 4);
		}
	}
	std::cout << "SumTest passed\n";
}

void CreationTest() {
	const size_t rows = 1;
	const size_t cols = 7;
	Matrix m(rows, cols);
	assert(m.getRows() == rows);
	assert(m.getCols() == cols);
	std::cout << "CreationTest passed\n";
}

void SingularTest() {
	Matrix m(1, 1);
	m[0][0] = 1;
	assert((m.getRows() == 1) && (m.getCols() == 1));
	assert(m[0][0] == 1);
	std::cout << "SingularTest passed\n";
}

void IndexationTest() {
	const size_t rows = 3;
	const size_t cols = 5;
	bool exceptrows = false;
	bool exceptcols = false;
	Matrix m(rows, cols);
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			m[i][j] = 1;
		}
	}
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			assert(m[i][j] == 1);
		}
	}
	try {
		int32_t a = m[4][1];
	}
	catch (std::out_of_range) {
		exceptrows = true;
	}
	assert(exceptrows);
	try {
		int32_t a = m[1][6];
	}
	catch (std::out_of_range) {
		exceptcols = true;
	}
	assert(exceptcols);
	std::cout << "IndexationTest passed\n";
}

void MultiplyTest() {
	const size_t rows = 2;
	const size_t cols = 8;
	Matrix m(rows, cols);
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			m[i][j] = -1;
		}
	}
	m *= 3;
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			assert(m[i][j] == -3);
		}
	}
	std::cout << "MultiplyTest passed\n";
}

void EqualTest() {
	const size_t rows = 3;
	const size_t cols = 5;
	Matrix q1(rows, cols);
	Matrix q2(rows, cols);
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			q1[i][j] = 1;
			q2[i][j] = 1;
		}
	}
	assert(q1 == q2);
	std::cout << "EqualTest passed\n";
}

void UnequalTest() {
	const size_t rows = 2;
	const size_t cols = 6;
	Matrix f1(rows, cols);
	Matrix f2(rows, cols);
	Matrix f3(cols, rows);
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			f1[i][j] = 1;
			f2[i][j] = 2;
			f3[j][i] = 1;
		}
	}
	assert((f1 != f2) && (f1 != f3));
	std::cout << "UnequalTest passed\n";
}

void SumLenTest() {
	bool except = false;
	const size_t rows = 3;
	const size_t cols = 7;
	Matrix m1(rows, cols);
	Matrix m2(cols, rows);
	try {
		Matrix m3 = m1 + m2;
	}
	catch (std::length_error) {
		except = true;
	}
	assert(except);
	std::cout << "SumLenTest passed\n";
}

void OutputTest() {
	const size_t rows = 3;
	const size_t cols = 5;
	Matrix m(rows, cols);
	for (size_t i=0; i < rows; i++) {
		for (size_t j=0; j < cols; j++) {
			m[i][j] = 1;
		}
	}
	std::ostringstream os;
	std::string ans = "1 1 1 1 1 \n1 1 1 1 1 \n1 1 1 1 1 \n";
	os << m;
	assert(os && (os.str() == ans));
}

int main() {
	std::cout << "Tests started\n";
	CreationTest();
	SingularTest();
	IndexationTest();
	MultiplyTest();
	SumTest();
	EqualTest();
	SumLenTest();
	UnequalTest();
	OutputTest();
	std::cout << "All tests successfully passed\n";
	return 0;
}