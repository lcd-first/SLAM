#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx_1;
std::mutex mtx_2;

int test_num = 1;

void print_block_1 (int n, char c) {

    mtx_1.lock();
    for (int i=0; i<n; ++i) {
        test_num = 1;
        std::cout<<test_num<<std::endl;
    }
    std::cout << '\n';
    mtx_1.unlock();
}
void print_block_2 (int n, char c) {

    mtx_2.lock();
    test_num = 2;
    for (int i=0; i<n; ++i) {
        test_num = 2;
        std::cout<<test_num<<std::endl;
    }
    mtx_2.unlock();
}

int main ()
{
    std::thread th1 (print_block_1,10000,'*');
    std::thread th2 (print_block_2,10000,'$');

    th1.join();
    th2.join();

    return 0;
}
