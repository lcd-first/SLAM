#include <iostream>

using namespace std;

template <typename T1,typename T2>             //模板函数声明与定义
T1 test(T1 tmp, T2 tmp1) {

    cout << "调用模板函数！" << endl;

    return (tmp + tmp1);
}

int test(int tmp, int tmp1) {                  //重载的普通函数

    cout << "调用普通函数！" << endl;

    return 0;
}

int main(void) {

    char tmp = 'c';
    int tmp1 = 0;
    int a = 5;

    cout << "test(5,'A')=" << test(a, tmp) << endl;
    cout << "test<>(5,0)=" << test<>(a, tmp1) << endl;       //使用<>显式的调用模板函数

    system("pause");

    return 0;
}

