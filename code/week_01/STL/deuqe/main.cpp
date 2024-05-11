#include <iostream>
#include <deque>
using namespace  std;
/*  代码书写顺序
 *  容器初始化 默认初始化 带参初始化
 *  容器赋值
 *  容器遍历
 *  插入，删除操作
 * */
int main() {
    int array[]={0,1,2,3,4};
    int array2[]={8,9,10,11,12,13,14};
    //默认构造
    deque<int> deque1;
    //带参数构造
    deque<int> deque2(array,array+3);
    //deque的迭代器
    deque<int>::iterator iter;
    //赋值
    deque1.assign(array,array+5);
    //遍历打印
    cout<< "deque1 中的元素为:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;
    cout<< "deque2 中的元素为:"<<endl;
    for(int i=0;i<deque2.size();i++) {
        cout<<deque2[i]<<" ";
    }
    cout<<endl;
    //赋值 操作和vector 相同 多了两个函数
    //deque.push_front(elem) 在容器头部插入一个元素
    //deque.pop_front() 删除容器头部元素
    cout<< "添加 100 到deque1 的头部"<<endl;
    deque1.push_front(100);
    cout<< "deque1 中的元素为:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;
    cout<< "删除 deque1 的头部元素"<<endl;
    deque1.pop_front();
    cout<< "deque1 中的元素为:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;
    //deque 删除
    for(iter=deque1.begin();iter!=deque1.end();) {
        if(*iter==3) {
            iter=deque1.erase(iter);
        }
        else {
            iter++;
        }
    }
    cout<< "deque1 中的元素为:"<<endl;
    for(int i=0;i<deque1.size();i++) {
        cout<<deque1[i]<<" ";
    }
    cout<<endl;

    return 0;
}
