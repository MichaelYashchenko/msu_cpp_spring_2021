#include "matrix.h"

Matrix::~Matrix() {
	if (arr != nullptr) {
		for (size_t i = 0; i != rows; ++i) {
			delete[] arr[i];
		}
	}
	delete[] arr;
}

Matrix::Proxy::Proxy(int* d, size_t s) {
	data = d;
	size = s;
}

int32_t& Matrix::Proxy::operator[] (size_t i) const{
	if (i > size) {
		throw std::out_of_range("");
	}
	return data[i];
}

Matrix::Proxy Matrix::operator[] (size_t i) const{
	if (i > rows) {
		throw std::out_of_range("");
	}
	return Matrix::Proxy(arr[i], cols);
}

Matrix::Matrix(size_t r, size_t c) {
	rows = r;
	cols = c;
	arr = new int*[rows];
	for (size_t i =0; i !=rows; ++i) {
		arr[i] = new int[cols];
	}
}

size_t Matrix::getRows() const {
	return rows;
}

size_t Matrix::getCols() const {
	return cols;
}

Matrix& Matrix::operator*= (int k) {
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			arr[i][j] *= k;
		}
	}
	return *this;
}

const bool Matrix::operator== (const Matrix& m) const {
	if ((rows != m.rows) || (cols != m.cols)){
		return false;
	}
	for (size_t i = 0; i != rows; ++i) {
		for (size_t j = 0; j != cols; ++j) {
			if (arr[i][j] != m.arr[i][j]){
				return false;
			}
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream &out, const Matrix &matrix) {
	for (size_t i=0; i < matrix.rows; i++) {
		for (size_t j=0; j < matrix.cols; j++) {
			out << matrix.arr[i][j] << " ";
		}
		out << '\n';
	}
	return out;
}

const bool Matrix::operator!= (const Matrix& m) const {
	return !(*this == m);
}

Matrix Matrix::operator+ (const Matrix& m) const {
	if(this->rows != m.rows || this->cols != m.cols)
		throw std::length_error("");

	Matrix result_matrix(m.rows, m.cols);
	for(size_t i=0; i < m.rows; i++) {
		for(size_t j=0; j < m.cols; j++) {
			result_matrix[i][j] = (*this)[i][j] + m[i][j];
		}
	}
	return result_matrix;
}