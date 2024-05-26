#include <iostream>
#include <memory>
using namespace std;

int main()
{
    // ʹ������ָ�����һ�� int �͵Ķ��ڴ�
    shared_ptr<int> ptr1(new int(520));
    cout << "ptr1������ڴ����ü���: " << ptr1.use_count() << endl;
    // ʹ������ָ�����һ���ַ������Ӧ�Ķ��ڴ�
    shared_ptr<char> ptr2(new char[12]);
    cout << "ptr2������ڴ����ü���: " << ptr2.use_count() << endl;
    // ��������ָ�����, �������κ��ڴ�
    shared_ptr<int> ptr3;
    cout << "ptr3������ڴ����ü���: " << ptr3.use_count() << endl;
    // ��������ָ�����, ��ʼ��Ϊ��
    shared_ptr<int> ptr4(nullptr);
    cout << "ptr4������ڴ����ü���: " << ptr4.use_count() << endl;

    return 0;
}

