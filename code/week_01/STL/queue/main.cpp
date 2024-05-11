#include <iostream>
#include <queue>
/* queue 是队列容器，是一种先进先出的容器
 *
 *
 *
 * */
using namespace std;
int main() {
    //默认构造函数
    queue<int> queInt;
    //push 往队尾添加元素
    //pop 从队头移除第一个元素
    queInt.push(10);
    queInt.push(11);
    queInt.push(12);
    queInt.push(13);
    cout<<"queInt 的大小: "<<queInt.size()<<endl;
    cout<<"移除队头第一个元素"<<endl;
    queInt.pop();
    cout<<"queInt 的大小: "<<queInt.size()<<endl;
    //数据存取
    // back 返回最后一个元素
    // front 返回第一个元素

    cout<<"queInt 的第一个元素 "<<queInt.front()<<endl;
    cout<<"queInt 的最后一个元素 "<<queInt.back()<<endl;

    //while 遍历
    cout<<"queInt 遍历"<<endl;
    while(queInt.empty()!= true){
        cout<<queInt.front()<<" ";
        queInt.pop();
    }
    cout<<endl;

    cout<<" queInt 的大小: "<<queInt.size()<<endl;

    return 0;
}
