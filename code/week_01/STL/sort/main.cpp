#include <iostream>
#include <algorithm>
#include <vector>
/*
 * �����㷨ֻ��vector ��deque ���������ṩ֧��
 * sort �� stable_sort ����ʹ�÷�ʽ��ͬ
 * partial_sort ���� ��������
 * Ĭ�϶�����������
 * */

using namespace std;



int main() {
    int a[]={0,1,20,3,40,5,6,7};

    vector<int> vecInt(a,a+5);

    // ���õ�һ���﷨��ʽ �� vecInt ��������
    sort(vecInt.begin(),vecInt.end());
    //���
    cout<<"sort����"<<endl;
    for(vector<int>::iterator iter=vecInt.begin();iter!=vecInt.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"partial_sort ���� ����"<<endl;
    partial_sort(vecInt.begin(),vecInt.begin()+2,vecInt.end());
    for(vector<int>::iterator iter=vecInt.begin();iter!=vecInt.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;




    return 0;
}
