#include <iostream>
#include <iomanip>
using namespace std;
class Time{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int h=0, int m=0, int s=0)
    :hour(h)
    ,minute(m)
    ,second(s){}
    
    friend istream& operator>>(istream& in, Time t);
    friend ostream& operator<<(ostream& out, const Time t);
    void ToStandard(){
        int totalSeconds = hour * 3600 + minute * 60 + second;
        totalSeconds %= 86400; // 处理超过24小时的情况
        if (totalSeconds < 0) totalSeconds += 86400; // 处理负数时间
        hour = totalSeconds / 3600;
        minute = (totalSeconds % 3600) / 60;
        second = totalSeconds % 60;
    
    }
    Time& operator++(){
        second++;
        return *this;
    }
    Time operator++(int){
        Time tmp = *this;
        second++;
        return tmp;
    }
    Time& operator--(){
        second--;
        return *this;
    }
    Time operator--(int){
        Time tmp = *this;
        second--;
        return tmp;
    }
    Time& operator+=(Time other){
        second += other.second;
        minute += other.minute;
        hour += other.hour;
        ToStandard();
        return *this;
    }
    Time& operator-=(Time other){
        second -= other.second;
        minute -= other.minute;
        hour -= other.hour;
        ToStandard();
        return *this;
    }
};
istream& operator>>(istream& in, Time t){
    in >> t.hour >> t.minute >> t.second;
    return in;
}
ostream& operator<<(ostream& out, const Time t){
    out << setfill('0') << setw(2) << t.hour << ":" << setfill('0') << setw(2) << t.minute << ":" << setfill('0') << setw(2) << t.second << endl;
    return out;
}
int main()
{
    int h, m, s;
    cin >> h >> m >> s;
    Time t1(h, m, s);
    cin >> h >> m >>s;
    Time t2(h, m, s);
    t1 += (t2++);
    cout << t1;
    
    t1 -= t2;
    cout << t1;
    
    cout << ++t2;
    
    t2 += (t1--);
    cout << t2;
    
    cout << --t1;
    
    t2 -= t1;
    cout << t2;
    
    
    return 0;
}
