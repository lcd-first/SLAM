#include <iostream>
#include <queue>
/* queue �Ƕ�����������һ���Ƚ��ȳ�������
 *
 *
 *
 * */
using namespace std;
int main() {
    //Ĭ�Ϲ��캯��
    queue<int> queInt;
    //push ����β���Ԫ��
    //pop �Ӷ�ͷ�Ƴ���һ��Ԫ��
    queInt.push(10);
    queInt.push(11);
    queInt.push(12);
    queInt.push(13);
    cout<<"queInt �Ĵ�С: "<<queInt.size()<<endl;
    cout<<"�Ƴ���ͷ��һ��Ԫ��"<<endl;
    queInt.pop();
    cout<<"queInt �Ĵ�С: "<<queInt.size()<<endl;
    //���ݴ�ȡ
    // back �������һ��Ԫ��
    // front ���ص�һ��Ԫ��

    cout<<"queInt �ĵ�һ��Ԫ�� "<<queInt.front()<<endl;
    cout<<"queInt �����һ��Ԫ�� "<<queInt.back()<<endl;

    //while ����
    cout<<"queInt ����"<<endl;
    while(queInt.empty()!= true){
        cout<<queInt.front()<<" ";
        queInt.pop();
    }
    cout<<endl;

    cout<<" queInt �Ĵ�С: "<<queInt.size()<<endl;

    return 0;
}
