#include <iostream>
#include <algorithm>
#include <vector>
/*
 * 排序算法只对vector 和deque 两个容器提供支持
 * sort 和 stable_sort 排序使用方式相同
 * partial_sort 排序， 部分排序
 * 默认都是升序排列
 * */

using namespace std;



int main() {
    int a[]={0,1,20,3,40,5,6,7};

    vector<int> vecInt(a,a+5);

    // 调用第一种语法格式 对 vecInt 进行排序
    sort(vecInt.begin(),vecInt.end());
    //输出
    cout<<"sort排序"<<endl;
    for(vector<int>::iterator iter=vecInt.begin();iter!=vecInt.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"partial_sort 部分 排序"<<endl;
    partial_sort(vecInt.begin(),vecInt.begin()+2,vecInt.end());
    for(vector<int>::iterator iter=vecInt.begin();iter!=vecInt.end();iter++) {
        cout<<*iter<<" ";
    }
    cout<<endl;




    return 0;
}
