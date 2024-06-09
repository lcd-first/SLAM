#include <iostream>
#include <stdio.h>

using namespace std;

template <typename T1,typename T2>             //模板函数声明与定义
T2 test(T1 tmp, T2 tmp1) {

    T2 tmp2 = tmp + tmp1;

    return tmp2;
}

int main(void) {

    cout << "test(10, 5)=" << test(10, 5) << endl;     //调用模板函数，模板函数通过传入的参数自动推导未实例化的类型
    cout << "test(5,'A')=" << test(5,'A') << endl;
    cout << "test(10.5, 5.5) =" << test(10.5, 5.5) << endl;

    system("pause");

    return 0;
}
