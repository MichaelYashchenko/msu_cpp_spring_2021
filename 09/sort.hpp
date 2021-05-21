#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <sstream>
#include <fstream>
#include <cassert>

const uint64_t MAX_SIZE = 1000000;

struct file_interface {
    std::ifstream reading;
    std::ofstream writing;
    std::string name;
    uint64_t size_ = 0;
};

uint64_t Numbers_in_file(const std::string &name) {
	std::streampos begin, end;
	std::ifstream file (name, std::ios_base::binary);
	begin = file.tellg();
	file.seekg (0, std::ios_base::end);
	end = file.tellg();
	return (end - begin) / sizeof(uint64_t);
}

file_interface& Merge_Files(file_interface& left, file_interface& right, uint64_t mark) {
	std::string name = "temp" + std::to_string(mark) + ".txt";
	std::ofstream write_data(name, std::ios_base::binary);
	left.reading.open(left.name, std::ios_base::binary);
	right.reading.open(right.name, std::ios_base::binary);
	uint64_t left_num;
	uint64_t right_num;
	uint64_t leftLen = left.size_;
	uint64_t rightLen = right.size_;
	uint64_t allLen = leftLen + rightLen;
	left.reading.read(reinterpret_cast<char *> (&left_num), sizeof(uint64_t));
	right.reading.read(reinterpret_cast<char *> (&right_num), sizeof(uint64_t));
	while (leftLen && rightLen) {
		if (left_num <= right_num) {
			write_data.write(reinterpret_cast<char *> (&left_num), sizeof(uint64_t));
			left.reading.read(reinterpret_cast<char *> (&left_num), sizeof(uint64_t));
			--leftLen;
		}
		else {
			write_data.write(reinterpret_cast<char *> (&right_num), sizeof(uint64_t));
			right.reading.read(reinterpret_cast<char *> (&right_num), sizeof(uint64_t));
			--rightLen;
		}
	}
	while (leftLen) {
		left.reading.read(reinterpret_cast<char *> (&left_num), sizeof(uint64_t));
		write_data.write(reinterpret_cast<char *> (&left_num), sizeof(uint64_t));
		--leftLen;
	}
	while (rightLen) {
		right.reading.read(reinterpret_cast<char *> (&right_num), sizeof(uint64_t));
		write_data.write(reinterpret_cast<char *> (&right_num), sizeof(uint64_t));
		--rightLen;
	}
	left.reading.close();
	right.reading.close();
	write_data.close();
	std::ifstream readBox(name, std::ios_base::binary);
	left.writing.open(left.name, std::ios_base::binary);
	while (allLen) {
		readBox.read(reinterpret_cast<char *> (&left_num), sizeof(uint64_t));
		left.writing.write(reinterpret_cast<char *> (&left_num), sizeof(uint64_t));
		--allLen;
	}
	readBox.close();
	left.writing.close();
	left.size_ += right.size_;
	remove(name.c_str());
	return left;
}

file_interface& Sort_Files(std::vector<file_interface>& files, uint64_t l, uint64_t r, const uint64_t mark) {
	if (l < r) {
		uint64_t m = l + (r - l) / 2;
		file_interface& left = Sort_Files(files, l, m, mark);
		file_interface& right = Sort_Files(files, m + 1, r, mark);
		return Merge_Files(left, right, mark);
	}
	return files[l];
}

void Merge(std::vector<uint64_t>& A, uint64_t l, uint64_t m, uint64_t r) {
	uint64_t i, j, k;
	uint64_t left_len = m - l + 1;
	uint64_t right_len = r - m;
	std::vector<uint64_t> L(left_len);
	std::vector<uint64_t> R(right_len);
	for (i = 0; i < left_len; ++i) {
		L[i] = A[l + i];
	}
	for (j = 0; j < right_len; ++j) {
		R[j] = A[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while (i < left_len && j < right_len) {
	    if (L[i] <= R[j]) {
			A[k++] = L[i++];
	    }
	    else {
			A[k++] = R[j++];
	    }
	}
	while (i < left_len) {
		A[k++] = L[i++];
	}
	while (j < right_len) {
		A[k++] = R[j++];
	}
}

void MergeSort(std::vector<uint64_t>& A, uint64_t l, uint64_t r) {
	if (l < r) {
		uint64_t m = l + (r - l) / 2;
		MergeSort(A, l, m);
		MergeSort(A, m + 1, r);
		Merge(A, l, m, r);
	}
}

std::vector<file_interface> make_files(uint64_t file_num, std::string input_name) {
	std::ifstream fin(input_name, std::ios_base::binary);
	std::vector<uint64_t> data(MAX_SIZE);
	std::vector<file_interface> files(file_num);
	for (size_t i = 0; i < file_num; ++i) {
		while (!fin.eof() && files[i].size_ < MAX_SIZE) {
		    fin.read(reinterpret_cast<char *>(&data[files[i].size_]), sizeof(uint64_t));
		    ++files[i].size_;
		}
		files[i].name = "file" + std::to_string(i) + ".txt";
		MergeSort(data, 0, files[i].size_ - 1);
		files[i].writing.open(files[i].name, std::ios_base::binary);
		for (size_t j = 0; j < files[i].size_; j++)
		    files[i].writing.write(reinterpret_cast<char *> (&data[j]), sizeof(uint64_t));
		files[i].writing.close();
	}
	return files;
}