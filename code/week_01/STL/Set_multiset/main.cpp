#include <iostream>
#include <set>
/*
 * set ��һ������������Ԫ����Ψһ�ģ�������Ԫ���ǰ���һ��˳�����еģ�Ԫ�ز����ǰ���˳�����,���Բ���ָ������λ��
 * set ���ú������������ݽṹʵ��,���������ƽ�������,�ڲ����ɾ���ϱ�vector ��
 * set ������ֱ�Ӵ�ȡԪ��
 * multiset ��set �Ĳ���� multiset ����������ͬ��С��Ԫ��
 * set Ĭ�ϴ�С��������
 * */

using namespace std;
class CStudent{
public:
    CStudent(int iID,string strName)
    {
        m_iID=iID;
        m_strName= strName;
    }
    int m_iID;
    string m_strName;
};

// α������
class StuFunctor
{
public:
    bool operator()(const CStudent &stu1,const CStudent &stu2)
    {
        return (stu1.m_iID<stu2.m_iID); //��������
    }

};





int main() {
    //Ĭ�Ϲ���
    set<int> setInt;  //��������
    set<int,greater<int>> setInt3;  //��������
    set<CStudent,StuFunctor> setStu; //
    multiset<int> multiInt;
    //������
    set<int>::iterator iter;
    //��ֵ ����
    setInt.insert(9);
    setInt.insert(0);
    setInt.insert(7);
    setInt.insert(1);
    setInt.insert(2);

    setInt3.insert(9);
    setInt3.insert(0);
    setInt3.insert(7);
    setInt3.insert(1);

    //��������
    set<int> setInt2(setInt);
    //����=������
    setInt2=setInt;
    cout<<"setInt �Ĵ�СΪ: "<<setInt.size()<<endl;
    // ture 1 ��     false 0 ����
    cout<<"setInt �Ƿ�Ϊ��: " << setInt.empty()<<endl;
    // ������
    cout<<"����setInt �е�����"<<endl;
    for(iter=setInt.begin();iter!=setInt.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"����setInt3 �е�����"<<endl;
    for(iter=setInt3.begin();iter!=setInt3.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
    //ɾ��
    // ɾ��set ��ֵΪ 7��Ԫ��
    cout<<"ɾ��set ��ֵΪ7��Ԫ��"<<endl;
    setInt.erase(7);
    cout<<"����setInt �е�����"<<endl;
    for(iter=setInt.begin();iter!=setInt.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
    //����
    //find(elem) ����elem Ԫ�أ�����ָ��elem�ĵ�����
    //count(elem) ����Ԫ���� ֵΪelem ��Ԫ�ظ���������meltiset ��˵���ݿ��ܴ���1
    //lower_bound(elem) ���ص�һ��>=elem Ԫ�صĵ�����
    //upper_bound(elem) ���ص�һ��>elem Ԫ�صĵ�����
    //equal_range(elem) ������������elem ��ȵ������޵�����������  ����Һ�

    //Ѱ�� Ԫ��ֵΪ9
    iter= setInt.find(9);
    cout<<"�ҵ���Ԫ��9 �ĵ�����ָ���Ԫ��Ϊ "<<*iter<<endl;

    pair<set<int>::iterator ,set<int>::iterator > p=setInt.equal_range(2);

    cout<<"����"<<*(p.first)<<"����"<<*(p.second)<<endl;


    setStu.insert(CStudent(3,"С��"));
    setStu.insert(CStudent(9,"С��"));
    setStu.insert(CStudent(5,"С��"));
    setStu.insert(CStudent(6,"С��"));
    setStu.insert(CStudent(2,"С��"));

    set<CStudent,StuFunctor>::iterator iter1;

    //����ѧ������
    cout<<"��ӡѧ��id"<<endl;
    for(iter1=setStu.begin();iter1!=setStu.end();iter1++){
        cout<< iter1->m_iID<<" ";
    }





    return 0;
}
