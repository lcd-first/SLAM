#include <iostream>
#include <map>
using namespace std;
/* map 是标准的关联式容器，一个map 是一个键值对序列，即(key,value) 对，她提供基于key 的快速检索能力
 * map 中key 值是唯一的，集合中的元素按一定的顺序排列，元素插入过程是按照排序规则插入，所以不能指定插入位置
 * map 的具体实现是采用红黑树变体的平衡二叉树的数据结构，在插入和删除操作上比vector快
 * map 可以直接存取key 所对应的value ，支持[] 操作符
 * */
class Student{
public:
    int id;
    string name;
    //默认构造函数
    Student(){

    }
    //带参构造函数
    Student(int id,string name) {
        this->id=id;
        this->name=name;
    }

};

int main() {
    // 默认构造对象
    map<int,Student> mapStu;
    map<int,string > map1;
    // map 元素的插入
    map1.insert(pair<int,string>(3,"小李"));
    map1.insert(pair<int,string>(4,"小张"));

    int key;
    string name;
    key=10;
    name="小王";
    pair<int,string> p(key,name);
    map1.insert(p);

    // 遍历元素
    map<int,string >::iterator iter1;
    cout<<"map1 中的元素"<<endl;
    for(iter1=map1.begin();iter1!=map1.end();iter1++) {
        pair<int,string> p = *iter1;
        int key=p.first;
        string value=p.second;
        cout<<key<<" "<<value<<" ";
    }
    cout<<endl;



    //自定义元素类型
    Student s1(1,"小孙");
    // 将学生的id 当作 map的键
    mapStu.insert(pair<int,Student>(s1.id  ,s1));
    Student s2(2,"小秦");
    mapStu[s2.id] =s2;

    map<int,Student>::iterator iter2;

    for(iter2=mapStu.begin();iter2!=mapStu.end();iter2++) {
        pair<int,Student> p= *iter2;
        int id= p.first;
        Student su= p.second;
        cout<<"id: "<<su.id<<" name: "<<su.name<<" ";
    }
    cout<<endl;
    // 查询
    // 获取学号为2的同学
    cout<<"寻找学号为2的同学"<<endl;
    iter2=mapStu.find(2);
    if(iter2==mapStu.end()) {
        cout <<"can not find";
    }
    else {
        pair<int ,Student> p2= *iter2;
        cout<<"找到 id "<<p2.second.id<<" name "<<p2.second.name;
    }
    cout<<endl;
    cout<<"寻找学号为20的同学"<<endl;
    iter2=mapStu.find(20);
    if(iter2==mapStu.end()) {
        cout <<"can not find";
    }
    else {
        pair<int ,Student> p2= *iter2;
        cout<<"找到 id "<<p2.second.id<<" name "<<p2.second.name;
    }
    cout<<endl;

    // 删除容器中指定的元素
    mapStu.erase(1);
    cout<<"删除 容器中 键 为1 的对象"<<endl;
    for(iter2=mapStu.begin();iter2!=mapStu.end();iter2++) {
        pair<int,Student> p= *iter2;
        int id= p.first;
        Student su= p.second;
        cout<<"id: "<<su.id<<" name: "<<su.name<<" ";
    }
    cout<<endl;

    return 0;

}
