#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;

void print_block (int n, char c) {

    mtx.lock();
    for (int i=0; i<n; ++i) { std::cout << c; }
    std::cout << '\n';
    mtx.unlock();
}

int main ()
{
    std::thread th1 (print_block,50,'*');//线程1：打印*
    std::thread th2 (print_block,50,'$');//线程2：打印$

    th1.join();
    th2.join();

    return 0;
}
