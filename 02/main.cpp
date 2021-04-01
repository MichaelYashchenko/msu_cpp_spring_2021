#include<vector>
#include "parser.hpp"

void Start_callback(void){
	std::cout << "Started parsing\n";
}

void Stop_callback(void){
	std::cout << "Stopped parsing\n";
}
std::vector<std::string> vec;

void GeneralTest(){

on_number Num_callback = [=] (int num){
	vec.push_back(std::to_string(num));
	std::cout << num << "\n";
};

on_str Str_callback = [=] (const std::string& str){
	vec.push_back(str);
	std::cout << str << "\n";
};

    TokenParser MyParser;
    MyParser.SetStartCallback(Start_callback);
    MyParser.SetEndCallback(Stop_callback);
    MyParser.SetDigitTokenCallback(Num_callback);
    MyParser.SetStringTokenCallback(Str_callback);


    std::string s("   jd  yh292222nxm    \t7fh\n  \tmm345\t  55  \n 2  35 008");
    MyParser.parse(s);
    std::vector<std::string> vec1 = {"jd", "yh292222nxm", "7fh", "mm345", "55", "2", "35", "008"};
    for (int i = 0; i < 8; ++i) {
		assert(vec[i] == vec1[i]);
	}
}

int main(){
    GeneralTest();
    std::cout << "test passed";
    return 0;
}