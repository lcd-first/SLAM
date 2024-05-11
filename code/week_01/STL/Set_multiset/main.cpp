#include <iostream>
#include <set>
/*
 * set 是一个集合容器，元素是唯一的，集合中元素是按照一定顺序排列的，元素插入是按照顺序插入,所以不能指定插入位置
 * set 采用红黑树变体的数据结构实现,红黑树属于平衡二叉树,在插入和删除上比vector 快
 * set 不可以直接存取元素
 * multiset 和set 的差别是 multiset 可以重新相同大小的元素
 * set 默认从小到大排列
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

// 伪函数类
class StuFunctor
{
public:
    bool operator()(const CStudent &stu1,const CStudent &stu2)
    {
        return (stu1.m_iID<stu2.m_iID); //升序排列
    }

};





int main() {
    //默认构造
    set<int> setInt;  //升序排列
    set<int,greater<int>> setInt3;  //降序排列
    set<CStudent,StuFunctor> setStu; //
    multiset<int> multiInt;
    //迭代器
    set<int>::iterator iter;
    //赋值 插入
    setInt.insert(9);
    setInt.insert(0);
    setInt.insert(7);
    setInt.insert(1);
    setInt.insert(2);

    setInt3.insert(9);
    setInt3.insert(0);
    setInt3.insert(7);
    setInt3.insert(1);

    //拷贝构造
    set<int> setInt2(setInt);
    //重载=操作符
    setInt2=setInt;
    cout<<"setInt 的大小为: "<<setInt.size()<<endl;
    // ture 1 空     false 0 不空
    cout<<"setInt 是否为空: " << setInt.empty()<<endl;
    // 迭代器
    cout<<"遍历setInt 中的数据"<<endl;
    for(iter=setInt.begin();iter!=setInt.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
    cout<<"遍历setInt3 中的数据"<<endl;
    for(iter=setInt3.begin();iter!=setInt3.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
    //删除
    // 删除set 中值为 7的元素
    cout<<"删除set 中值为7的元素"<<endl;
    setInt.erase(7);
    cout<<"遍历setInt 中的数据"<<endl;
    for(iter=setInt.begin();iter!=setInt.end();iter++){
        cout<<*iter<<" ";
    }
    cout<<endl;
    //查找
    //find(elem) 查找elem 元素，返回指向elem的迭代器
    //count(elem) 返回元素中 值为elem 的元素个数，对于meltiset 来说数据可能大于1
    //lower_bound(elem) 返回第一个>=elem 元素的跌代器
    //upper_bound(elem) 返回第一个>elem 元素的迭代器
    //equal_range(elem) 返回容器中与elem 相等的上下限的两个迭代器  左闭右合

    //寻找 元素值为9
    iter= setInt.find(9);
    cout<<"找到的元素9 的迭代器指向的元素为 "<<*iter<<endl;

    pair<set<int>::iterator ,set<int>::iterator > p=setInt.equal_range(2);

    cout<<"下限"<<*(p.first)<<"上限"<<*(p.second)<<endl;


    setStu.insert(CStudent(3,"小张"));
    setStu.insert(CStudent(9,"小李"));
    setStu.insert(CStudent(5,"小王"));
    setStu.insert(CStudent(6,"小赵"));
    setStu.insert(CStudent(2,"小孙"));

    set<CStudent,StuFunctor>::iterator iter1;

    //遍历学生数据
    cout<<"打印学生id"<<endl;
    for(iter1=setStu.begin();iter1!=setStu.end();iter1++){
        cout<< iter1->m_iID<<" ";
    }





    return 0;
}
