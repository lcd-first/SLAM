#include <iostream>
#include <deque>
using namespace  std;
/*  ������д˳��
 *  ������ʼ�� Ĭ�ϳ�ʼ�� ���γ�ʼ��
 *  ������ֵ
 *  ��������
 *  ���룬ɾ������
 * */
int main() {
    int array[]={0,1,2,3,4};
    int array2[]={8,9,10,11,12,13,14};
    //Ĭ�Ϲ���
    deque<int> deque1;
    //����������
    deque<int> deque2(array,array+3);
    //deque�ĵ�����
    deque<int>::iterator iter;
    //��ֵ
    deque1.assign(array,array+5);
    //������ӡ
    cout<< "deque1 �е�Ԫ��Ϊ:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;
    cout<< "deque2 �е�Ԫ��Ϊ:"<<endl;
    for(int i=0;i<deque2.size();i++) {
        cout<<deque2[i]<<" ";
    }
    cout<<endl;
    //��ֵ ������vector ��ͬ ������������
    //deque.push_front(elem) ������ͷ������һ��Ԫ��
    //deque.pop_front() ɾ������ͷ��Ԫ��
    cout<< "��� 100 ��deque1 ��ͷ��"<<endl;
    deque1.push_front(100);
    cout<< "deque1 �е�Ԫ��Ϊ:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;
    cout<< "ɾ�� deque1 ��ͷ��Ԫ��"<<endl;
    deque1.pop_front();
    cout<< "deque1 �е�Ԫ��Ϊ:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;
    //deque ɾ��
    for(iter=deque1.begin();iter!=deque1.end();) {
        if(*iter==3) {
            iter=deque1.erase(iter);
        }
        else {
            iter++;
        }
    }
    cout<< "deque1 �е�Ԫ��Ϊ:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;

    return 0;
}
