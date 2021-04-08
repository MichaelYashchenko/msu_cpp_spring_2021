#include "parser.hpp"


void DefaultTest(){
    std::vector<std::string> vec;
    on_start_or_stop Start_callback = [](){std::cout << "DefaultTest start" << std::endl;};
    on_start_or_stop Stop_callback = [](){std::cout << "DefaultTest end" << std::endl;};
    on_number Num_callback = [&] (std::uint64_t num){
	    vec.push_back(std::to_string(num));
	    std::cout << num << "\n";
    };

    on_str Str_callback = [&] (const std::string& str){
	    vec.push_back(str);
	    std::cout << str << "\n";
    };

    TokenParser MyParser;
    MyParser.SetStartCallback(Start_callback);
    MyParser.SetEndCallback(Stop_callback);
    MyParser.SetDigitTokenCallback(Num_callback);
    MyParser.SetStringTokenCallback(Str_callback);


    std::string s("   jd  yh292222nxm    \t7fh\n  \tmm345\t  55  \n 2  35 8");
    MyParser.parse(s);
    std::vector<std::string> vec1 = {"jd", "yh292222nxm", "7fh", "mm345", "55", "2", "35", "8"};
    for (int i = 0; i < 8; ++i){
		assert(vec[i] == vec1[i]);
	}
}

void BigNumbersTest(){
    std::vector<std::string> nums;
	std::vector<std::string> strings;
	on_number Num_callback = [&](std::uint64_t num){
		nums.push_back(std::to_string(num));
		std::cout << num << std::endl;
	};
	on_str Str_callback = [&](const std::string& str){
		strings.push_back(str);
		std::cout << str << std::endl;
	};

	std::string s("18446744073709551615   18446744073709551616");
	TokenParser MyParser;
	MyParser.SetDigitTokenCallback(Num_callback);
	MyParser.SetStringTokenCallback(Str_callback);

	MyParser.parse(s);

    std::vector<std::string> vec1 = {"18446744073709551615"};
	std::vector<std::string> vec2 = {"18446744073709551616"};
	for (int i=0; i < vec1.size(); i++) {
		assert(vec1[i] == nums[i]);
	}
	for (int i=0; i < vec2.size(); i++) {
		assert(vec2[i] == strings[i]);
	}
}

void StartEndCallbacksTest(){
	bool Start_call = false;
	bool End_call = false;
    on_start_or_stop Start_callback = [&] (){
		Start_call = true;
		std::cout << "Start SC callback" << std::endl;
	};
	on_start_or_stop End_callback = [&] (){
		End_call = true;
		std::cout << "End SC callback" << std::endl;
	};

    std::string s("   jd  yh292222nxm    \t7fh\n  \tmm345\t  55  \n 2  35 008");
	TokenParser MyParser;
	MyParser.SetStartCallback(Start_callback);
	MyParser.SetEndCallback(End_callback);

	MyParser.parse(s);
    std::cout << Start_call << " " << End_call << "\n";
	assert(Start_call && End_call);
}

void NoCallbacksTest(){
	std::string s("   jd  yh292222nxm    \t7fh\n  \tmm345\t  55  \n 2  35 008");
	bool noexception = true;
	TokenParser MyParser;
	try {
		MyParser.parse(s);
	}
	catch(...) {
		noexception = false;
	}
	assert(noexception);
}

void SingleCharacterTest(){
	std::vector<std::string> nums;
	std::vector<std::string> strings;
	on_number Num_callback = [&](std::uint64_t num){
		nums.push_back(std::to_string(num));
		std::cout << num << std::endl;
	};
	on_str Str_callback = [&](const std::string& str){
		strings.push_back(str);
		std::cout << str << std::endl;
	};
	std::string s1("1");
	std::string s2("a");
	TokenParser MyParser;
	MyParser.SetDigitTokenCallback(Num_callback);
	MyParser.SetStringTokenCallback(Str_callback);

	MyParser.parse(s1);
	MyParser.parse(s2);

	std::vector<std::string> vec1 = {"1"};
	std::vector<std::string> vec2 = {"a"};
	for (int i=0; i < vec1.size(); i++) {
		assert(vec1[i] == nums[i]);
	}
	for (int i=0; i < vec2.size(); i++) {
		assert(vec2[i] == strings[i]);
	}
}

void EmptyInputTest(){
	bool Digit_call = false;
	bool String_call = false;
	on_number Num_callback = [&](std::uint64_t num){
		Digit_call = true;
		std::cout << num << std::endl;
	};
	on_str Str_callback = [&](const std::string& str){
		String_call = true;
		std::cout << str << std::endl;
	};

	std::string s("");
	TokenParser MyParser;
	MyParser.SetDigitTokenCallback(Num_callback);
	MyParser.SetStringTokenCallback(Str_callback);

	MyParser.parse(s);

	assert(!Digit_call && !String_call);
}

void SpacesInputTest() {
	bool Digit_call = false;
	bool String_call = false;
	on_number Num_callback = [&](std::uint64_t num) {
		Digit_call = true;
		std::cout << num << std::endl;
	};
	on_str Str_callback = [&](const std::string &str) {
		String_call = true;
		std::cout << str << std::endl;
	};

	std::string s("   ");
	TokenParser MyParser;
	MyParser.SetDigitTokenCallback(Num_callback);
	MyParser.SetStringTokenCallback(Str_callback);

	MyParser.parse(s);

	assert(!Digit_call && !String_call);
}

int main(){
    DefaultTest();
    BigNumbersTest();
    StartEndCallbacksTest();
    NoCallbacksTest();
    EmptyInputTest();
    SpacesInputTest();
    SingleCharacterTest();

    std::cout << "test passed";
    return 0;
}