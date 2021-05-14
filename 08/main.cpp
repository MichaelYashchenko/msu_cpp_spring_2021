#include "threadpool.cpp"

int f1(int x) {
    std::cout << "Test 1\n";
    return x * 5;
}

int f2(int a, int b, int c) {
    std::cout << "Test 2\n";
    return (a + b - c) * 10;
}

int f3(std::string str){
    std::cout << "Test 3\n";
    return str.length();
}

int main(){
    std::cout << "Starting tests\n";
    ThreadPool pool(3);
    auto task1 = pool.exec(f1, 22);
    int test1 = task1.get();
    assert(test1 == 110);
    auto task2 = pool.exec(f2, 10, 15, 5);
    int test2 = task2.get();
    assert(test2 == 200);
    auto task3 =pool.exec(f3, "the last one");
    int test3 = task3.get();
    assert(test3 == 12);
    std::cout << "All tests passed\n";
}