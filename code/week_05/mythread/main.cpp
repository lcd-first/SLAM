#include <iostream>
#include "mythread.h"
#include<string>
#include<math.h>
using namespace std;
class Task
{
public:
    void process()
    {
        //cout << "run........." << endl;
        //������������
        long i=1000000;
        while(i!=0)
        {
            int j = sqrt(i);
            i--;
        }
    }
};
int main(void)
{
    threadPool<Task> pool(6);//6���̣߳�vector
    std::string str;
    while (1)
    {
        Task *tt = new Task();
        //ʹ������ָ��
        pool.append(tt);//��ͣ��������������Ƕ���queue����Ϊֻ�й̶����߳���
        cout<<"��ӵ����������� "<<pool.tasks_queue.size()<<endl;;
        delete tt;
    }
}
