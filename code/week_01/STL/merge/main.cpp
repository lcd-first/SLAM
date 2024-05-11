#include <algorithm>
#include <iostream>
#include <vector>
/*
 * merge() 函数，将两个已经排好序的序列，合成一个有序的序列
 * OutPutIterator merge(InputIterator1 first1,InputIterator1 last1,
 *                      InputIterator2 first2,InputIterator2 last2,
 *                      OutputIterator result);
 *OutputIterator merge (InputIterator1 first1, InputIterator1 last1,
 *                      InputIterator2 first2, InputIterator2 last2,
 *                      OutputIterator result,  Compare comp);
 *
 * firs1t为第一个容器的首迭代器，last1为第一个容器的末迭代器；
 * first2为第二个容器的首迭代器，last2为容器的末迭代器； *
 * result为存放结果的容器，comapre为比较函数（可略写，默认为合并为一个升序序列）。
 *
 * */
using namespace std;
int main() {
  int a1[] = {0, 4, 5, 6, 7};
  int a2[] = {3, 20, 60, 80};
  
  vector<int> vecInt1(a1, a1 + 5);
  vector<int> vecInt2(a2, a2 + 4);

  sort(vecInt1.begin(), vecInt1.end());
  sort(vecInt2.begin(), vecInt2.end());

  vector<int> vecInt3(vecInt1.size() + vecInt2.size());
  cout << "vecInt3 中原数据" << endl;
  for (vector<int>::iterator iter = vecInt3.begin(); iter != vecInt3.end();
       iter++) {
    cout << *iter << " ";
  }
  cout << endl;
  cout << "merge 合并排序结果" << endl;
  merge(vecInt1.begin(), vecInt1.end(), vecInt2.begin(), vecInt2.end(),
        vecInt3.begin());
  for (vector<int>::iterator iter = vecInt3.begin(); iter != vecInt3.end();
       iter++) {
    cout << *iter << " ";
  }
  cout << endl;

  return 0;
}
