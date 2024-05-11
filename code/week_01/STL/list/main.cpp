#include <iostream>
#include <list>
using namespace std;
/*  list 双向链表容器，可以高效的插入删除元素
 *  list 不可以随机存取元素，不支持at.(pos) ，和[] 操作符
 *
 * */
int main() {
    int array[]={0,1,2,3,4};
    int array2[]={8,9,10,11,12,13,14};
    //默认构造
    list<int> list1;
    //带参构造
    list<int> list2(array,array+4);
    list<int> list3(array2,array2+4);
    //迭代器
    list<int>::iterator iter;

    list1=list2;
    cout<<"打印list2 中的元素"<<endl;
    for(iter=list2.begin(); iter!=list2.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    //交换 list3 和 list2 容器元素相互交换
    list3.swap(list2);
    //list 插入
    cout<<"list1 头部插入元素100"<<endl;
    iter=list1.begin();
    list1.insert(iter,100);
    // 打印list1中的元素
    cout<<"打印list1 中的元素"<<endl;
    for(iter=list1.begin(); iter!=list1.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    //list 的删除
    cout<<"删除list1 中大小为2的元素 "<<endl;
    list1.remove(2);
    cout<<"打印list1 中的元素"<<endl;
    for(list<int>::iterator iter2=list1.begin(); iter2!=list1.end();iter2++) {
        cout<<*iter2<<" ";
    }
    cout<<endl;
    // 反转列表
    list1.reverse();
    cout<<"反转list1 中的元素"<<endl;
    for(list<int>::iterator iter2=list1.begin(); iter2!=list1.end();iter2++) {
        cout<<*iter2<<" ";
    }

    return 0;

}
