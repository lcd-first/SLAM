#include <iostream>
#include <stack>
/* 栈是堆栈容器, 先进后出的容器
 * stack 容器没有迭代器，因为栈不允许遍历
 * */
using namespace std;
int main() {
    //默认构造
    stack<int> staInt;

    // push() 和 pop() 方法
    staInt.push(10); //  往栈头添加元素
    // 拷贝构造
    stack<int> staInt2(staInt);
    staInt.pop(); // 从栈头移除第一个元素
    // stack 的数据存取
    staInt.push(1);
    staInt.push(2);
    staInt.push(3);
    //打印出栈顶元素
    cout<<"打印栈顶元素:"<<endl;
    // top 函数  只返回栈顶元素 不删除栈顶元素
    cout<<staInt.top()<<endl;
    cout<<staInt.top()<<endl;
    // stack 的大小
    cout<<"stack 的大小:"<<staInt.size()<<endl;

    cout<<"循环出栈"<<endl;
    // 循环出栈操作 empty 判断栈是否为空
    while(staInt.empty()!= true) {
        cout<<staInt.top()<<"  ";
        staInt.pop();
    }
    //while(!staInt.empty())

    return 0;
}
