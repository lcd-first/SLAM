#include <iostream>
#include <vector>
using namespace  std;
int main() {

    int array[]={0,1,2,3,4};
    int array2[]={8,9,10,11,12,13,14};
    // Ĭ�Ϲ���
    vector<int> vecInt;
    //����������
    vector<int> vecInt2(array,array+3);
    // ��������
    vector<int> vecInt3(vecInt2);
    // vector������
    vector<int>::iterator iter; //������Ϊiter

    //��ֵ
    vecInt.assign(array2,array2+5);  //����ҿ�

    vecInt2.assign(vecInt.begin(),vecInt.end());
    //����vecInt���� ��ӡ���
    cout<< "vecInt ԭ����"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt[i]<<" ";
    }
    cout<<endl;
    cout<< "vecInt2 ԭ����"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt2[i]<<" ";
    }
    cout<<endl;
    //β������Ƴ�����
    vecInt.push_back(10);  //β������Ԫ��10
    cout<< "vecInt β������Ԫ��10��"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt[i]<<" ";
    }
    cout<<endl;

    vecInt.pop_back(); //ɾ��β��Ԫ��

    cout<< "vecInt ɾ��β��Ԫ�غ�"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt[i]<<" ";
    }
    cout<<endl;

    //vector ��ɾ��
    // ���������������Ԫ��ɾ���� ����Ԫ�ش�ӡ
    // Ϊʲô��ôд����Ϊ ɾ��Ԫ�ػᵼ�µ�����ʧЧ
    for (iter = vecInt.begin();  iter!=vecInt.end();) {
        if(*iter==10) {
            iter=vecInt.erase(iter);
        }
        else {
            iter++;
        }
    }
    // ��������ӡvector����Ԫ��
    cout<<"ɾ�� vecInt �д�СΪ10��Ԫ��"<<endl;
    for(iter = vecInt.begin();iter!= vecInt.end();iter++)
        cout << *iter<<" ";
    cout<<endl;
    //vector�Ĳ���
    iter= vecInt.begin()+2;

    vecInt.insert(iter,100);
    cout<<"���� 100 ��vecInt��"<<endl;
    for(iter = vecInt.begin();iter!= vecInt.end();iter++)
        cout << *iter<<" ";
    cout<<endl;
    return 0;
}
