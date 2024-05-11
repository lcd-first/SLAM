#include <iostream>
#include <map>
using namespace std;
/* map �Ǳ�׼�Ĺ���ʽ������һ��map ��һ����ֵ�����У���(key,value) �ԣ����ṩ����key �Ŀ��ټ�������
 * map ��key ֵ��Ψһ�ģ������е�Ԫ�ذ�һ����˳�����У�Ԫ�ز�������ǰ������������룬���Բ���ָ������λ��
 * map �ľ���ʵ���ǲ��ú���������ƽ������������ݽṹ���ڲ����ɾ�������ϱ�vector��
 * map ����ֱ�Ӵ�ȡkey ����Ӧ��value ��֧��[] ������
 * */
class Student{
public:
    int id;
    string name;
    //Ĭ�Ϲ��캯��
    Student(){

    }
    //���ι��캯��
    Student(int id,string name) {
        this->id=id;
        this->name=name;
    }

};

int main() {
    // Ĭ�Ϲ������
    map<int,Student> mapStu;
    map<int,string > map1;
    // map Ԫ�صĲ���
    map1.insert(pair<int,string>(3,"С��"));
    map1.insert(pair<int,string>(4,"С��"));

    int key;
    string name;
    key=10;
    name="С��";
    pair<int,string> p(key,name);
    map1.insert(p);

    // ����Ԫ��
    map<int,string >::iterator iter1;
    cout<<"map1 �е�Ԫ��"<<endl;
    for(iter1=map1.begin();iter1!=map1.end();iter1++) {
        pair<int,string> p = *iter1;
        int key=p.first;
        string value=p.second;
        cout<<key<<" "<<value<<" ";
    }
    cout<<endl;



    //�Զ���Ԫ������
    Student s1(1,"С��");
    // ��ѧ����id ���� map�ļ�
    mapStu.insert(pair<int,Student>(s1.id  ,s1));
    Student s2(2,"С��");
    mapStu[s2.id] =s2;

    map<int,Student>::iterator iter2;

    for(iter2=mapStu.begin();iter2!=mapStu.end();iter2++) {
        pair<int,Student> p= *iter2;
        int id= p.first;
        Student su= p.second;
        cout<<"id: "<<su.id<<" name: "<<su.name<<" ";
    }
    cout<<endl;
    // ��ѯ
    // ��ȡѧ��Ϊ2��ͬѧ
    cout<<"Ѱ��ѧ��Ϊ2��ͬѧ"<<endl;
    iter2=mapStu.find(2);
    if(iter2==mapStu.end()) {
        cout <<"can not find";
    }
    else {
        pair<int ,Student> p2= *iter2;
        cout<<"�ҵ� id "<<p2.second.id<<" name "<<p2.second.name;
    }
    cout<<endl;
    cout<<"Ѱ��ѧ��Ϊ20��ͬѧ"<<endl;
    iter2=mapStu.find(20);
    if(iter2==mapStu.end()) {
        cout <<"can not find";
    }
    else {
        pair<int ,Student> p2= *iter2;
        cout<<"�ҵ� id "<<p2.second.id<<" name "<<p2.second.name;
    }
    cout<<endl;

    // ɾ��������ָ����Ԫ��
    mapStu.erase(1);
    cout<<"ɾ�� ������ �� Ϊ1 �Ķ���"<<endl;
    for(iter2=mapStu.begin();iter2!=mapStu.end();iter2++) {
        pair<int,Student> p= *iter2;
        int id= p.first;
        Student su= p.second;
        cout<<"id: "<<su.id<<" name: "<<su.name<<" ";
    }
    cout<<endl;

    return 0;

}
