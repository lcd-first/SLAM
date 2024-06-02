#include <iostream>
#include <thread>


using namespace  std;

void  mythread() {

    cout <<" my thread start"<< endl;

}
class  TA{
public:
    void operator()(){

        cout<<"operator "<<endl;


    }


};


int main() {
    //主线程在main 开始执行


  //  thread mythread1(mythread);  //创建线程，开始执行

   // mythread1.join();  //阻塞主线程，等待子线程执行完毕，join 执行完毕，主线程继续走

    //detach()  传统规律： 主线程等待子程序，  detach 分离， 主线程和子线程不汇合，主线程不等待子线程执行完毕。
    // detach 后不能用join   工程中常用 join ，应用范围多

    //joinable  是否可以成功使用join（） 或 detach() ;

    //if(mythread1.joinable()) {
  //      cout<<"join == true"<<endl;
  //  }
   // else {
  //      cout<<"join == false"<<endl;
  //  }
 //   cout<<"main thread"<<endl;

    TA ta;
    thread mythrate2(ta);
    mythrate2.join();

    cout<<" main end"<<endl;



    return 0;
}
