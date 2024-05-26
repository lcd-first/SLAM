#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
int main()
{
    // �¼�Ԫ1970.1.1ʱ��
    system_clock::time_point epoch;
    duration<int, ratio<60*60*24>> day(1);
    // �¼�Ԫ1970.1.1ʱ�� + 1��
    system_clock::time_point ppt(day);
    using dday = duration<int, ratio<60 * 60 * 24>>;
    // �¼�Ԫ1970.1.1ʱ�� + 10��
    time_point<system_clock, dday> t(dday(10));
    // ϵͳ��ǰʱ��
    system_clock::time_point today = system_clock::now();
    // ת��Ϊtime_tʱ������
    time_t tm = system_clock::to_time_t(today);
    cout << "�����������:    " << ctime(&tm);
    time_t tm1 = system_clock::to_time_t(today+day);
    cout << "�����������:    " << ctime(&tm1);
    time_t tm2 = system_clock::to_time_t(epoch);
    cout << "�¼�Ԫʱ��:      " << ctime(&tm2);
    time_t tm3 = system_clock::to_time_t(ppt);
    cout << "�¼�Ԫʱ��+1��:  " << ctime(&tm3);
    time_t tm4 = system_clock::to_time_t(t);
    cout << "�¼�Ԫʱ��+10��: " << ctime(&tm4);
}


