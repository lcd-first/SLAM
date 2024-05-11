#include <iostream>
#include <algorithm>
#include <vector>
/*�����㷨
 * adjacent_find()
 * ���ܣ� ��iterator �Ա�ʶԪ�ط�Χ�ڣ�����һ������Ԫ�أ��ҵ��򷵻����Ԫ�صĵ�һ��Ԫ�صĵ�����
 * binary_serch()
 * ���ܣ� ���ֲ��ң������������в���value ���ҵ��򷵻�true
 * count()
 * ���ܣ� ���õ��ڲ��������ѱ�־��Χ�ڵ�Ԫ��������ֵ�Ƚϣ�������ȵĸ���
 * find()
 * ����: ��ָ����Χ�ڲ��Һ�Ŀ��Ԫ��ֵ��ȵĵ�һ��Ԫ��,��������������ʽ����
 *      ���ҳɹ��� ����ָ��Ŀ��Ԫ�صĵ�����
 *      ����ʧ�ܣ� ��last ָ����ͬ
 * find_if()
 * ���ܣ� ��find ��ͬ,��ͬ���� ǰ����Ҫ��ȷָ������Ԫ�ص�ֵ�����������Զ�����ҹ���
 * search()
 * ���ܣ� ���������� A�в�������B ��һ�γ��ֵ�λ��
 * ���� [first1, last1) ��Χ�ڵ�һ�� [first2, last2) ������
 * ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
 *                         ForwardIterator first2, ForwardIterator last2);
 * ���� [first1, last1) ��Χ�ڣ��� [first2, last2) �������� pred ����ĵ�һ��������
 * ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
 *                          ForwardIterator first2, ForwardIterator last2,
 *                          BinaryPredicate pred);
 * */


using namespace std;
int main() {


    int a1[]= {0,4,4,6,7};
    //��������
    int a2[]={6,7};

    vector<int> vecInt1(a1,a1+5);

    vector<int> vecInt2(a2,a2+2);

    vector<int>::iterator iter= adjacent_find(vecInt1.begin(),vecInt1.end());
    cout<<"�ҵ�һ����ͬԪ�صĵ�����ָ���Ԫ��Ϊ: "<<*iter<<endl;

    sort(vecInt1.begin(), vecInt1.end());
    cout<<"��vecInt1 �в�ѯ�Ƿ����Ԫ�� 7"<<endl;
    bool bFind= binary_search(vecInt1.begin(),vecInt1.end(),7);
    cout<<"vecInt1 �Ƿ����Ԫ��7:"<<bFind<<endl;

    int iCount= count(vecInt1.begin(),vecInt1.end(),4);
    cout<<"vecInt1 ����4��ȵ�Ԫ�ظ���Ϊ: "<<iCount<<endl;

    cout<<"find ����vecInt1�д�СΪ6��Ԫ��"<<endl;
    iter= find(vecInt1.begin(),vecInt1.end(),6);
    if(iter!= vecInt1.end()) {
        cout<<"���ҳɹ�"<<endl;
    }
    else {
        cout<<"����ʧ��"<<endl;
    }

    vector<int>::iterator iter2= search(vecInt1.begin(),vecInt1.end(),
                                      vecInt2.begin(),vecInt2.end());
    if(iter2!=vecInt1.end()) {
        cout<<"���ҳɹ�"<<endl;
        cout<<"��vecInt1 �е�һ��vecInt2���е���ʼλ��Ϊ: "<<iter2-vecInt1.begin()<<" *iter2= "<<*iter2<<endl;
    }


    return 0;
}
