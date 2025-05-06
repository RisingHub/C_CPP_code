#include <iostream>

using namespace std;
#define PI 3.14159
class Circle{

    private:

        double radius;
        
    public:

        Circle():radius(0)
        {}

        Circle(double _r):radius(_r)
        {}

        double getRadius()const;

        void setRadius(double _r);

        double getArea()const;

        double getPerimeter()const;

        bool operator>(const Circle& other)const;//根据半径比较

        bool operator<(const Circle& other)const;

        bool operator==(const Circle& other)const;

        bool operator!=(const Circle& other)const;

};

ostream& operator<<(ostream& out ,const Circle& circle )//输出：circle:radius=1,area=3.14159,perimeter=
{
    out << "circle:radius=" << circle.getRadius() << ",area=" << circle.getArea() << ",perimeter=" << circle.getPerimeter() <<endl;
    return out;
}
istream& operator>>(istream& in,Circle& circle)//输入半径
{
    double r;
    in >> r;
    circle.setRadius(r);
    return in;
}
int main()
{
    Circle c1, c2;
    cin >> c1 >> c2;
    
    cout << "c1:radius=" << c1.getRadius() << ",area=" << c1.getArea() << ",perimeter=" << c1.getPerimeter() << endl;
    cout << "c2:radius=" << c2.getRadius() << ",area=" << c2.getArea() << ",perimeter=" << c2.getPerimeter() << endl;
    if(c1 > c2)
    {
        cout << "c1>c2 is true\n";
    }
    else
    {
        cout << "c1>c2 is false\n";
    }
    
    if(c1 < c2)
    {
        cout << "c1<c2 is true\n";
    }
    else
    {
        cout << "c1<c2 is false\n";
    }
    
    if(c1 == c2)
    {
        cout << "c1==c2 is true\n";
    }
    else
    {
        cout << "c1==c2 is false\n";
    }
    
    if(c1 != c2)
    {
        cout << "c1!=c2 is true\n";
    }
    else
    {
        cout << "c1!=c2 is false\n";
    }
    return 0;
}

double Circle::getRadius()const
{
    return radius;
}
void Circle::setRadius(double _r)
{
    radius = _r;
}
double Circle::getArea()const
{
    return PI*radius*radius;
}
double Circle::getPerimeter()const
{
    return 2*PI*radius;
}
bool Circle::operator>(const Circle& other)const//根据半径比较
{
    return radius > other.radius;
}
bool Circle::operator<(const Circle& other)const
{
    return !(radius >= other.radius);
}
bool Circle::operator==(const Circle& other)const
{
    return radius == other.radius;
}
bool Circle::operator!=(const Circle& other)const
{
    return !(radius == other.radius);
}
