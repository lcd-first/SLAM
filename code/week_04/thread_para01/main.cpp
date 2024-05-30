#include <iostream>
#include <thread>

using namespace std;

class Para {
public:
    Para() {
        cout<< "Create Para"<<endl;
    }
    Para(const Para& p) {
        cout<<"Copy Para"<<endl;
    }
    ~Para(){
        cout <<"Drop Para"<<endl;
    }
    string name;
};
void ThreadMain(int p1,float  p2,string str,Para p4) {
    this_thread::sleep_for(100ms);
    cout<<"Thread Main "<< p1<<p2<<str<<endl;
}

int main() {

    thread th;{
        float f1=12.1f;
        //所有的参数做做复制
        Para p;
        p.name="test Para class";
        th = thread(ThreadMain,101,f1,"test string para",p);
    }
    //堵塞进程
    th.join();
    return 0;
}


