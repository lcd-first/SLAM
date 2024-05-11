#include <iostream>
#include <algorithm>
#include <vector>
/*查找算法
 * adjacent_find()
 * 功能： 在iterator 对标识元素范围内，查找一对相邻元素，找到则返回这对元素的第一个元素的跌代器
 * binary_serch()
 * 功能： 二分查找，在有序序列中查找value ，找到则返回true
 * count()
 * 功能： 利用等于操作符，把标志范围内的元素与输入值比较，返回相等的个数
 * find()
 * 功能: 在指定范围内查找和目标元素值相等的第一个元素,适用于所有序列式容器
 *      查找成功： 返回指向目标元素的迭代器
 *      查找失败： 和last 指向相同
 * find_if()
 * 功能： 和find 相同,不同的是 前者需要明确指明查找元素的值，后者允许自定义查找规则
 * search()
 * 功能： 用于在序列 A中查找序列B 第一次出现的位置
 * 查找 [first1, last1) 范围内第一个 [first2, last2) 子序列
 * ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
 *                         ForwardIterator first2, ForwardIterator last2);
 * 查找 [first1, last1) 范围内，和 [first2, last2) 序列满足 pred 规则的第一个子序列
 * ForwardIterator search (ForwardIterator first1, ForwardIterator last1,
 *                          ForwardIterator first2, ForwardIterator last2,
 *                          BinaryPredicate pred);
 * */


using namespace std;
int main() {


    int a1[]= {0,4,4,6,7};
    //查找序列
    int a2[]={6,7};

    vector<int> vecInt1(a1,a1+5);

    vector<int> vecInt2(a2,a2+2);

    vector<int>::iterator iter= adjacent_find(vecInt1.begin(),vecInt1.end());
    cout<<"找到一对相同元素的迭代器指向的元素为: "<<*iter<<endl;

    sort(vecInt1.begin(), vecInt1.end());
    cout<<"在vecInt1 中查询是否存在元素 7"<<endl;
    bool bFind= binary_search(vecInt1.begin(),vecInt1.end(),7);
    cout<<"vecInt1 是否存在元素7:"<<bFind<<endl;

    int iCount= count(vecInt1.begin(),vecInt1.end(),4);
    cout<<"vecInt1 中与4相等的元素个数为: "<<iCount<<endl;

    cout<<"find 查找vecInt1中大小为6的元素"<<endl;
    iter= find(vecInt1.begin(),vecInt1.end(),6);
    if(iter!= vecInt1.end()) {
        cout<<"查找成功"<<endl;
    }
    else {
        cout<<"查找失败"<<endl;
    }

    vector<int>::iterator iter2= search(vecInt1.begin(),vecInt1.end(),
                                      vecInt2.begin(),vecInt2.end());
    if(iter2!=vecInt1.end()) {
        cout<<"查找成功"<<endl;
        cout<<"在vecInt1 中第一个vecInt2序列的起始位置为: "<<iter2-vecInt1.begin()<<" *iter2= "<<*iter2<<endl;
    }


    return 0;
}
