#include <iostream>
#include <list>
using namespace std;
/*  list ˫���������������Ը�Ч�Ĳ���ɾ��Ԫ��
 *  list �����������ȡԪ�أ���֧��at.(pos) ����[] ������
 *
 * */
int main() {
    int array[]={0,1,2,3,4};
    int array2[]={8,9,10,11,12,13,14};
    //Ĭ�Ϲ���
    list<int> list1;
    //���ι���
    list<int> list2(array,array+4);
    list<int> list3(array2,array2+4);
    //������
    list<int>::iterator iter;

    list1=list2;
    cout<<"��ӡlist2 �е�Ԫ��"<<endl;
    for(iter=list2.begin(); iter!=list2.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    //���� list3 �� list2 ����Ԫ���໥����
    list3.swap(list2);
    //list ����
    cout<<"list1 ͷ������Ԫ��100"<<endl;
    iter=list1.begin();
    list1.insert(iter,100);
    // ��ӡlist1�е�Ԫ��
    cout<<"��ӡlist1 �е�Ԫ��"<<endl;
    for(iter=list1.begin(); iter!=list1.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    //list ��ɾ��
    cout<<"ɾ��list1 �д�СΪ2��Ԫ�� "<<endl;
    list1.remove(2);
    cout<<"��ӡlist1 �е�Ԫ��"<<endl;
    for(list<int>::iterator iter2=list1.begin(); iter2!=list1.end();iter2++) {
        cout<<*iter2<<" ";
    }
    cout<<endl;
    // ��ת�б�
    list1.reverse();
    cout<<"��תlist1 �е�Ԫ��"<<endl;
    for(list<int>::iterator iter2=list1.begin(); iter2!=list1.end();iter2++) {
        cout<<*iter2<<" ";
    }

    return 0;

}
