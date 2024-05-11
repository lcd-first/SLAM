#include <iostream>
#include <vector>
using namespace  std;
int main() {

    int array[]={0,1,2,3,4};
    int array2[]={8,9,10,11,12,13,14};
    // 默认构造
    vector<int> vecInt;
    //带参树构造
    vector<int> vecInt2(array,array+3);
    // 拷贝构造
    vector<int> vecInt3(vecInt2);
    // vector迭代器
    vector<int>::iterator iter; //变量名为iter

    //赋值
    vecInt.assign(array2,array2+5);  //左闭右开

    vecInt2.assign(vecInt.begin(),vecInt.end());
    //遍历vecInt数据 打印输出
    cout<< "vecInt 原数据"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt[i]<<" ";
    }
    cout<<endl;
    cout<< "vecInt2 原数据"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt2[i]<<" ";
    }
    cout<<endl;
    //尾部添加移除操作
    vecInt.push_back(10);  //尾部插入元素10
    cout<< "vecInt 尾部插入元素10后"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt[i]<<" ";
    }
    cout<<endl;

    vecInt.pop_back(); //删除尾部元素

    cout<< "vecInt 删除尾部元素后"<< endl;
    for (int i = 0; i < vecInt.size(); ++i) {
        cout << vecInt[i]<<" ";
    }
    cout<<endl;

    //vector 的删除
    // 引入迭代器，遍历元素删除， 遍历元素打印
    // 为什么这么写，因为 删除元素会导致迭代器失效
    for (iter = vecInt.begin();  iter!=vecInt.end();) {
        if(*iter==10) {
            iter=vecInt.erase(iter);
        }
        else {
            iter++;
        }
    }
    // 迭代器打印vector容器元素
    cout<<"删除 vecInt 中大小为10的元素"<<endl;
    for(iter = vecInt.begin();iter!= vecInt.end();iter++)
        cout << *iter<<" ";
    cout<<endl;
    //vector的插入
    iter= vecInt.begin()+2;

    vecInt.insert(iter,100);
    cout<<"插入 100 到vecInt中"<<endl;
    for(iter = vecInt.begin();iter!= vecInt.end();iter++)
        cout << *iter<<" ";
    cout<<endl;
    return 0;
}
