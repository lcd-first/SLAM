#include <iostream>
using namespace std;

template <typename T>


void Swap(T & a, T &b) {
    T tmp = a;
    a=b;
    b=tmp;
}
int main() {
    int a= 10, b=20;
    Swap(a,b); //编译器自动推导
    //Swap<int>(a,b); //手动推导
    cout<< "a="<<a<<" b= "<<b<<endl;
    return 0;
}