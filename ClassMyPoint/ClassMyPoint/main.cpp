#include <iostream>
#include <cmath>
using namespace std;

class MyPoint{
public:
    MyPoint();
    MyPoint(double, double);
    double GetX()const;
    double GetY()const;
    void SetX(double _x);
    void SetY(double _y);
    double distance(const MyPoint&)const;
    virtual void print()const;
    MyPoint add(const MyPoint&);
    virtual void increment();
    virtual void decrement();
    virtual void input(istream&);
    friend MyPoint operator+(const MyPoint&,const MyPoint&);
    friend MyPoint& operator++(MyPoint&);
//    friend MyPoint operator++(MyPoint&, int);
    friend MyPoint& operator--(MyPoint&);
//    friend MyPoint operator--(MyPoint&, int);
    friend ostream& operator<<(ostream&,const MyPoint&);
    friend istream& operator>>(istream&,MyPoint&);
private:
    double x;
    double y;
};


class ThreeDPoint : public MyPoint
{
public:
    ThreeDPoint();
    ThreeDPoint(double, double, double);
    double GetZ()const;
    void SetZ(double);
    double distance(const ThreeDPoint&)const;
    void print()const override;
    ThreeDPoint add(const ThreeDPoint&);
    void increment() override;
    void decrement() override;
    void input(istream&) override;
    friend ThreeDPoint operator++(ThreeDPoint&, int);
    friend ThreeDPoint operator--(ThreeDPoint&, int);
private:
    double z;
};

int main()
{
    ThreeDPoint t1, t2;
        cin >> t1 >> t2;

        cout << "The disctance of " << t1 << " and " << t2
             << " is " << t1.distance(t2) << "." << endl;
        
        cout << t1 << "+" << t2 << "=" << t1.add(t2) << endl;
        
        cout << "++" << t1 << "=";
        cout << (++t1) << endl;
        
        cout << t1 << "++=";
        cout << (t1++) << endl;
        
        cout << "--" << t1 << "=";
        cout << (--t1) << endl;
        
        cout << t1 << "--=";
        cout << (t1--) << endl;
   
    return 0;
}
MyPoint::MyPoint():x(0),y(0){}
MyPoint::MyPoint(double _x, double _y) : x(_x), y(_y){}
double MyPoint::GetX()const{
    return x;
}
double MyPoint::GetY()const{
    return y;
}
void MyPoint::SetX(double _x){
    x = _x;
}
void MyPoint::SetY(double _y){
    y = _y;
}
double MyPoint::distance(const MyPoint& other)const{
    return sqrt( pow(x-other.x, 2) + pow(y-other.y, 2) );
}
void MyPoint::print()const{
    cout << "（" << GetX() << "," << GetY() << "）" << endl;
}
MyPoint MyPoint::add(const MyPoint& other){
    MyPoint& tmp = *this;
    tmp.x += other.x;
    tmp.y += other.y;
    return tmp;
}
void MyPoint::increment(){
    x++;
    y++;
}
void MyPoint::decrement(){
    x--;
    y--;
}
void MyPoint::input(istream& in){
    in >> x >> y;
}
MyPoint operator+(const MyPoint& p1,const MyPoint& p2){
    return MyPoint(p1.x+p2.x, p1.y+p2.y);
}
MyPoint& operator++(MyPoint& p){
    p.increment();
    return p;
}
ThreeDPoint operator++(ThreeDPoint& p, int){
    ThreeDPoint tmp(p);
    p.increment();
    return tmp;
}
MyPoint& operator--(MyPoint& p){
    p.decrement();
    return p;
}
ThreeDPoint operator--(ThreeDPoint& p, int){
    ThreeDPoint tmp(p);
    p.decrement();
    return tmp;
}
ostream& operator<<(ostream& out,const MyPoint& p){
    p.print();
    return out;
}
istream& operator>>(istream& in,MyPoint& p){
    p.input(in);
    return in;
}

ThreeDPoint::ThreeDPoint()
:MyPoint()
,z(0){}
ThreeDPoint::ThreeDPoint(double _x, double _y, double _z)
:MyPoint(_x, _y)
,z(_z){}
double ThreeDPoint::GetZ()const{
    return z;
}
void ThreeDPoint::SetZ(double _z){
    z = _z;
}
double ThreeDPoint::distance(const ThreeDPoint& other)const{
    double dx = GetX() - other.GetX();
    double dy = GetY() - other.GetY();
    double dz = GetZ() - other.GetZ();
    return sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
}
void ThreeDPoint::increment(){
    MyPoint::increment();
    z++;
}
void ThreeDPoint::decrement(){
    MyPoint::decrement();
    z--;
}
void ThreeDPoint::input(istream& in){
    MyPoint::input(in);
    in >> z;
}
void ThreeDPoint::print()const{
    cout << "(" << GetX() << "," << GetY() << "," << GetZ() << ")";
}
ThreeDPoint ThreeDPoint::add(const ThreeDPoint& other){
    ThreeDPoint t = *this;
    t.MyPoint::add(other);
    t.z += other.z;
    return t;
}

