#include <algorithm>
#include <iostream>
#include <vector>
/*
 * merge() �������������Ѿ��ź�������У��ϳ�һ�����������
 * OutPutIterator merge(InputIterator1 first1,InputIterator1 last1,
 *                      InputIterator2 first2,InputIterator2 last2,
 *                      OutputIterator result);
 *OutputIterator merge (InputIterator1 first1, InputIterator1 last1,
 *                      InputIterator2 first2, InputIterator2 last2,
 *                      OutputIterator result,  Compare comp);
 *
 * firs1tΪ��һ���������׵�������last1Ϊ��һ��������ĩ��������
 * first2Ϊ�ڶ����������׵�������last2Ϊ������ĩ�������� *
 * resultΪ��Ž����������comapreΪ�ȽϺ���������д��Ĭ��Ϊ�ϲ�Ϊһ���������У���
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
  cout << "vecInt3 ��ԭ����" << endl;
  for (vector<int>::iterator iter = vecInt3.begin(); iter != vecInt3.end();
       iter++) {
    cout << *iter << " ";
  }
  cout << endl;
  cout << "merge �ϲ�������" << endl;
  merge(vecInt1.begin(), vecInt1.end(), vecInt2.begin(), vecInt2.end(),
        vecInt3.begin());
  for (vector<int>::iterator iter = vecInt3.begin(); iter != vecInt3.end();
       iter++) {
    cout << *iter << " ";
  }
  cout << endl;

  return 0;
}
