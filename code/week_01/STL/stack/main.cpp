#include <iostream>
#include <stack>
/* ջ�Ƕ�ջ����, �Ƚ����������
 * stack ����û�е���������Ϊջ���������
 * */
using namespace std;
int main() {
    //Ĭ�Ϲ���
    stack<int> staInt;

    // push() �� pop() ����
    staInt.push(10); //  ��ջͷ���Ԫ��
    // ��������
    stack<int> staInt2(staInt);
    staInt.pop(); // ��ջͷ�Ƴ���һ��Ԫ��
    // stack �����ݴ�ȡ
    staInt.push(1);
    staInt.push(2);
    staInt.push(3);
    //��ӡ��ջ��Ԫ��
    cout<<"��ӡջ��Ԫ��:"<<endl;
    // top ����  ֻ����ջ��Ԫ�� ��ɾ��ջ��Ԫ��
    cout<<staInt.top()<<endl;
    cout<<staInt.top()<<endl;
    // stack �Ĵ�С
    cout<<"stack �Ĵ�С:"<<staInt.size()<<endl;

    cout<<"ѭ����ջ"<<endl;
    // ѭ����ջ���� empty �ж�ջ�Ƿ�Ϊ��
    while(staInt.empty()!= true) {
        cout<<staInt.top()<<"  ";
        staInt.pop();
    }
    //while(!staInt.empty())

    return 0;
}
