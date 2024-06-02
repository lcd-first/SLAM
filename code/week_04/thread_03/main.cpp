#include <iostream>
#include  <thread>
using  namespace  std;
/*
 * 传递临时对象作为线程参数
 * 临时对象作为线程参数
 *  线程ID 概念
 *  临时对象构造时机抓捕
 * 传递类对象，智能指针作为线程参数
 * 用成员函数指针做线程函数
 * */
void myprint(const int & i , char *pmybuf)
{
    cout<< i<<endl;
    cout << pmybuf<<endl;
    return ;
}


int main() {
    // 1. 传递临时对象作为线程参数
    int myvar = 10;
    int &mvaray = myvar;
    char  mybuf[] = "this is a test";
    thread mytobj(myprint,myvar,mybuf);
    mytobj.join();
    return 0;
}
