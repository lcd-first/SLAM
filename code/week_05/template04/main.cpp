#include <iostream> //包含标准输入输出流库
using namespace std;

template<class T> //定义一个模板类，其数据成员为T类型数组
class TestClass
{
public:
    T buffer[10]; //T类型数组

    T getData(int j); //成员函数声明，用于获取该数组中的元素
};

template<class T> //定义模板类的成员函数，返回指定下标处的数据
T TestClass<T>::getData(int j)
{
    return *(buffer+j);
};

int main() //主函数
{
    TestClass<char> ClassInstA; //定义一个模板类的对象，类型是char
    int i;
    char cArr[6] = "abcde"; //定义一个char类型的数据数组
    for (i = 0; i < 5; i++) //赋值给buffer数组
        ClassInstA.buffer[i] = cArr[i];
    for (i = 0; i < 5; i++) //依次输出buffer中元素的值
    {
        char res = ClassInstA.getData(i); //调用成员函数getData
        cout << res << " "; //打印结果
    }
    cout << endl; //换行

    TestClass<double> ClassInstF; //定义一个模板类的对象，类型是double
    double fArr[6] = {12.1, 23.2, 34.3, 45.4, 56.5, 67.6}; //定义一个double类型的数据数组
    for (i = 0; i < 6; i++) //赋值给buffer数组
        ClassInstF.buffer[i] = fArr[i] - 10;
    for (i = 0; i < 6; i++) //依次输出buffer中元素的值
    {
        double res = ClassInstF.getData(i); //调用成员函数getData
        cout << res << " "; //打印结果
    }
    cout << endl; //换行

    return 0; //程序执行成功，返回0
}