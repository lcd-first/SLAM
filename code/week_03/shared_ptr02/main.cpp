#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Test
{
public:
    Test()
    {
        cout << "construct Test..." << endl;
    }
    Test(int x)
    {
        cout << "construct Test, x = " << x << endl;
    }
    Test(string str)
    {
        cout << "construct Test, str = " << str << endl;
    }
    ~Test()
    {
        cout << "destruct Test ..." << endl;
    }
};

int main()
{
    // ʹ������ָ�����һ�� int �͵Ķ��ڴ�, �ڲ����ü���Ϊ 1
    shared_ptr<int> ptr1 = make_shared<int>(520);
    cout << "ptr1������ڴ����ü���: " << ptr1.use_count() << endl;

    shared_ptr<Test> ptr2 = make_shared<Test>();
    cout << "ptr2������ڴ����ü���: " << ptr2.use_count() << endl;

    shared_ptr<Test> ptr3 = make_shared<Test>(520);
    cout << "ptr3������ڴ����ü���: " << ptr3.use_count() << endl;

    shared_ptr<Test> ptr4 = make_shared<Test>("����Ҫ��Ϊ������������!!!");
    cout << "ptr4������ڴ����ü���: " << ptr4.use_count() << endl;
    return 0;
}


