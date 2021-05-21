#include "sort.hpp"

void Test() {
    std::string input_name("input.txt");

	std::ofstream file(input_name, std::ios::binary | std::ios::out);
	for (int i = 0; i < 10000; ++i) {
		auto *n = new uint64_t(std::rand() % 100);
		file.write(reinterpret_cast<char *>(n), sizeof(uint64_t));
		delete n;
	}
	file.close();
    
	uint64_t size_of_input = Numbers_in_file(input_name);
	uint64_t file_num = size_of_input / MAX_SIZE;
	if (size_of_input % MAX_SIZE)
		++file_num; 
	std::vector<file_interface> files = make_files(file_num, input_name);
	if (file_num != 1) {
		uint64_t m = file_num / 2 - 1;
		std::thread left(Sort_Files, std::ref(files), 0, m, 1);
		std::thread right(Sort_Files, std::ref(files), m + 1, file_num - 1, 2);
		left.join();
		right.join();
		Merge_Files(files[0], files[m + 1], 0);
		for (int i = 1; i != file_num; ++i) {
			std::remove(files[i].name.c_str());
		}
	}
	
	std::cout << "\nWriting results to file \"output.txt\" and checking if it\'s sorted correctly:\n"; 
	std::ofstream fout("output.txt", std::ios::binary | std::ios::out);
	std::ifstream fin1("file0.txt", std::ios::binary | std::ios::in);
	bool flag = true;
	bool flag1 = true;
	while (!fin1.eof()) {
		uint64_t n, pred_n;
		fin1.read(reinterpret_cast<char *>(&n), sizeof(uint64_t));
		if (flag && flag1) {
			flag1 = false;
			continue;
		}
		if (!flag) {
			fout.write(reinterpret_cast<char *>(&pred_n), sizeof(uint64_t));
			assert(pred_n <= n);
		}
		flag = false;
		pred_n = n;
	}
	fout.close();
	std::cout << "SORTING WAS CORRECT\n";
	std::remove(files[0].name.c_str());
}

int main() {
    Test();
	return 0;
}