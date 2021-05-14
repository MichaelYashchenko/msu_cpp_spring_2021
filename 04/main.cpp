#include "BigInt.hpp"

void ConstructorTest() {
	BigInt num1;
	BigInt num2(-12345);
	BigInt num3("123456789012345678901234567890");

	char* ans1 = num1.NumToStr();
	assert(ans1 == nullptr);

	char* ans2 = num2.NumToStr();
	const char* correctAns2 = "-12345";
	for (int i = 0; i < strlen(ans2); i++) {
		assert(ans2[i] = correctAns2[i]);
	}

	char* ans3 = num3.NumToStr();
	const char* correctAns3 = "123456789012345678901234567890";
	for (int i = 0; i < strlen(ans3); i++) {
		assert(ans3[i] = correctAns3[i]);
	}
    std::cout << "Constructor test passed!\n";
}

void SumTest() {
	BigInt num1("1000");
	BigInt num2("999");
	BigInt num3("-1000");
	BigInt num4("-999");
	int num5 = 1000;
	BigInt num6("0");
	BigInt num7("1");
	char* ans;
	const char* correctAns;

	BigInt num = num1 + num2;
	ans = num.NumToStr();
	correctAns = "1999";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num2 + num3;
	ans = num.NumToStr();
	correctAns = "-1";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 + num4;
    	ans = num.NumToStr();
	correctAns = "1";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num3 + num4;
	ans = num.NumToStr();
	correctAns = "-1999";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 + num5;
	ans = num.NumToStr();
	correctAns = "2000";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num2 + num6;
	ans = num.NumToStr();
	correctAns = "999";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num2 + num7;
	ans = num.NumToStr();
	correctAns = "1000";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}
    	std::cout << "Sum test passed!\n";
}

void SubtractTest() {
	BigInt num1("1000");
	BigInt num2("999");
	BigInt num3("-1000");
	BigInt num4("-999");
	int num5 = 1000;
	BigInt num6("0");
	BigInt num7("1");
	char* ans;
	const char* correctAns;

	BigInt num = num1 - num2;
	ans = num.NumToStr();
	correctAns = "1";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num3 - num2;
	ans = num.NumToStr();
	correctAns = "-1999";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 - num4;
	ans = num.NumToStr();
	correctAns = "1999";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num3 - num4;
	ans = num.NumToStr();
	correctAns = "-1";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num4 - num3;
	ans = num.NumToStr();
	correctAns = "1";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 - num5;
	ans = num.NumToStr();
	correctAns = "0";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 - num6;
	ans = num.NumToStr();
	correctAns = "1000";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 - num7;
	ans = num.NumToStr();
	correctAns = "999";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}
    	std::cout << "Subtract test passed!\n";
}

void MultiplyTest() {
	BigInt num1("12");
	BigInt num2("1234");
	BigInt num3("-12");
	BigInt num4("-1234");
	BigInt num5("0");
	int num6 = 12;
	BigInt num7("1");
	char* ans;
	const char* correctAns;

	BigInt num = num1 * num2;
	ans = num.NumToStr();
	correctAns = "14808";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num3 * num2;
	ans = num.NumToStr();
	correctAns = "-14808";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num3 * num4;
	ans = num.NumToStr();
	correctAns = "14808";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 * num5;
	ans = num.NumToStr();
	correctAns = "0";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 * num6;
	ans = num.NumToStr();
	correctAns = "14808";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}

	num = num1 * num7;
	ans = num.NumToStr();
	correctAns = "12";
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}
    	std::cout << "Multiply test passed!\n";
}

void CompareTest() {
	BigInt num1("1000");
	BigInt num2("999");
	BigInt num3("-1000");
	BigInt num4("-999");
	BigInt num5("1000");
	BigInt num6("0");
	BigInt num7("-1");
	assert(num1 == num5);
	assert(num1 > num2);
	assert(num1 != num3);
	assert(num1 > num3);
	assert(num3 < num4);
	assert(num4 >= num3);
	assert(num7 < num6);
    	std::cout << "Compare test passed!\n";
}

void CopyTest() {
	BigInt num1("1234");
	BigInt num2(num1);
    	BigInt num3("1234");
	BigInt num4("4321");
	assert(num1 == num2);
	num4 = num3;
	assert(num3 == num4);
    	std::cout << "Copy test passed!\n";
}

void MoveTest() {
	BigInt num1("1234");
	BigInt num2(std::move(num1));
	BigInt num3("1234");
	BigInt num4("4321");
	char* ans;
	const char* correctAns = "1234";

	assert(!num1.NumToStr());
	ans = num2.NumToStr();
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}


	num4 = std::move(num3);
	assert(!num3.NumToStr());
	ans = num4.NumToStr();
	for (int i = 0; i < strlen(ans); i++) {
		assert(ans[i] = correctAns[i]);
	}
    	std::cout << "Move test passed!\n";
}

void OutTest() {
	BigInt num(-1234567890);
	std::ostringstream oss;
	std::string ans = "-1234567890";
	oss << num;
	assert(oss && (oss.str() == ans));
    	std::cout << "Out test passed!\n";
}

int main() {
    	std::cout << "Test started!\n";
	ConstructorTest();
	SumTest();
	SubtractTest();
	CompareTest();
	MultiplyTest();
	CopyTest();
	MoveTest();
	OutTest();
	std::cout << "All tests successfully passed!\n" << std::endl;
	return 0;
}