#include <iostream>
#include <memory>
using namespace std;

unique_ptr<int> func()
{
    return unique_ptr<int>(new int(520));
}

int main()
{
    // ͨ�����캯����ʼ��
    unique_ptr<int> ptr1(new int(10));
    // ͨ��ת������Ȩ�ķ�ʽ��ʼ��
    unique_ptr<int> ptr2 = move(ptr1);
    unique_ptr<int> ptr3 = func();

    return 0;
}
