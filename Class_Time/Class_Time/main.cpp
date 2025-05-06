#include <iostream>
#include <iomanip>

using namespace std;

class Time{
private:
    int hour;
    int minute;
    int second;
    
    void normalize();
public:
    Time(int _hour = 0, int _minute = 0, int _second = 0)
    :hour(_hour)
    ,minute(_minute)
    ,second(_second)
    {
        normalize();
    }
    
    Time(const Time& other)
    {
        hour = other.hour;
        minute = other.minute;
        second = other.second;
        normalize();
    }
    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, Time& t);
    
    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);
    
    Time& operator++();
    Time operator++(int);
    
    Time& operator--();
    Time operator--(int);
};

int main()
{
    Time t1, t2;
    cin >> t1 >> t2;
    
    t1 += (t2++);
    cout << t1;
    
    t1 -= t2;
    cout << t1;
    
    ++t2;
    cout << t2;
    
    t2 += (t1--);
    cout << t2;
    
    --t1;
    cout << t1;
    
    t2 -= t1;
    cout << t2;
    
    
    return 0;
}

void Time::normalize()
{
    while(second < 0)
    {
        second += 60;
        minute--;
    }
    while(minute < 0)
    {
        minute += 60;
        hour--;
    }
    while(hour < 0)
    {
        hour += 24;
    }
    
    minute += second/60;
    second %= 60;
    
    hour = (hour + minute/60) % 24;
    minute %= 60;
}

istream& operator>>(istream& in, Time& t)
{
    in >> t.hour >> t.minute >> t.second;
    return in;
}
ostream& operator<<(ostream& out, Time& t)
{
    out << setfill('0') << setw(2) << t.hour << ":" << setfill('0') << setw(2) << t.minute << ":" << setfill('0') << setw(2) << t.second << endl;
    return out;
}

Time& Time::operator+=(const Time& other)
{
    second += other.second;
    minute += other.minute;
    hour += other.hour;
    normalize();
    return *this;
}
Time& Time::operator-=(const Time& other)
{
    second -= other.second;
    minute -= other.minute;
    hour -= other.hour;
    normalize();
    return *this;
}
Time& Time::operator++()
{
    second++;
    normalize();
    return *this;
}
Time Time::operator++(int)
{
    normalize();
    Time tmp = *this;
    second++;
    normalize();
    return tmp;
}
Time& Time::operator--()
{
    second--;
    normalize();
    return *this;
}
Time Time::operator--(int)
{
    normalize();
    Time tmp = *this;
    second--;
    normalize();
    return tmp;
}
