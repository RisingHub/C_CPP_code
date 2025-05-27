#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 类声明部分（仅包含函数原型）
class Quadrilateral {
private:
    double length1, length2, width1, width2;
    static int count;

public:
    Quadrilateral();
    Quadrilateral(double, double, double, double);
    Quadrilateral(const Quadrilateral&);
    virtual ~Quadrilateral();

    double getLength1() const;
    double getLength2() const;
    double getWidth1() const;
    double getWidth2() const;
    virtual string getType() const = 0;
    static int getCount();

    void setLength1(double);
    void setLength2(double);
    void setWidth1(double);
    void setWidth2(double);

    virtual double getArea() const = 0;
    double getPerimeter() const;

    virtual void printInfo(ostream&) const = 0;
    virtual bool operator==(const Quadrilateral&) const = 0;
};

ostream& operator<<(ostream&, const Quadrilateral&);

class Trapezoid : public Quadrilateral {
private:
    double height;

public:
    Trapezoid(double, double, double);
    string getType() const override;
    double getArea() const override;
    void printInfo(ostream&) const override;
    bool operator==(const Quadrilateral&) const override;
};

class Rectangle : public Trapezoid {
public:
    Rectangle(double, double);
    string getType() const override;
    void printInfo(ostream&) const override;
    bool operator==(const Quadrilateral&) const override;
};

class Square : public Rectangle {
public:
    Square(double);
    string getType() const override;
    void printInfo(ostream&) const override;
    bool operator==(const Quadrilateral&) const override;
};

// 主函数
int main() {
    vector<Quadrilateral*> shapes;
    char ch;

    for (int i = 0; i < 6; i++) {
        cin >> ch;
        switch (ch) {
            case 'R': {
                double l, w;
                cin >> l >> w;
                shapes.push_back(new Rectangle(l, w));
                break;
            }
            case 'S': {
                double s;
                cin >> s;
                shapes.push_back(new Square(s));
                break;
            }
            case 'T': {
                double l1, l2, w;
                cin >> l1 >> l2 >> w;
                shapes.push_back(new Trapezoid(l1, l2, w));
                break;
            }
        }
    }

    vector<Quadrilateral*> shapesByArea = shapes;
    vector<Quadrilateral*> shapesByPerimeter = shapes;

    sort(shapesByArea.begin(), shapesByArea.end(),
        [](const Quadrilateral* a, const Quadrilateral* b) {
            return a->getArea() < b->getArea();
        });

    sort(shapesByPerimeter.begin(), shapesByPerimeter.end(),
        [](const Quadrilateral* a, const Quadrilateral* b) {
            return a->getPerimeter() < b->getPerimeter();
        });

    for (auto shape : shapesByArea) {
        cout << *shape << endl;
    }
    cout << endl;

    for (auto shape : shapesByPerimeter) {
        cout << *shape << endl;
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}

// 函数定义部分（位于main函数之后）
int Quadrilateral::count = 0;

Quadrilateral::Quadrilateral() : length1(0), length2(0), width1(0), width2(0) { count++; }

Quadrilateral::Quadrilateral(double l1, double l2, double w1, double w2)
    : length1(l1), length2(l2), width1(w1), width2(w2) { count++; }

Quadrilateral::Quadrilateral(const Quadrilateral& other)
    : length1(other.length1), length2(other.length2),
      width1(other.width1), width2(other.width2) { count++; }

Quadrilateral::~Quadrilateral() { count--; }

double Quadrilateral::getLength1() const { return length1; }
double Quadrilateral::getLength2() const { return length2; }
double Quadrilateral::getWidth1() const { return width1; }
double Quadrilateral::getWidth2() const { return width2; }
int Quadrilateral::getCount() { return count; }

void Quadrilateral::setLength1(double l1) { length1 = l1; }
void Quadrilateral::setLength2(double l2) { length2 = l2; }
void Quadrilateral::setWidth1(double w1) { width1 = w1; }
void Quadrilateral::setWidth2(double w2) { width2 = w2; }

double Quadrilateral::getPerimeter() const {
    return length1 + length2 + width1 + width2;
}

ostream& operator<<(ostream& os, const Quadrilateral& q) {
    q.printInfo(os);
    return os;
}

Trapezoid::Trapezoid(double l1, double l2, double w)
    : Quadrilateral(l1, l2, w, w),
      height(sqrt(w * w - pow(abs(l1 - l2) / 2.0, 2))) {}

string Trapezoid::getType() const { return "Trapezoid"; }

double Trapezoid::getArea() const {
    return 0.5 * (getLength1() + getLength2()) * height;
}

void Trapezoid::printInfo(ostream& os) const {
    os << "Trapezoid:len1=" << getLength1()
       << ",len2=" << getLength2()
       << ",width=" << getWidth1()
       << ",area=" << getArea()
       << ",perimeter=" << getPerimeter();
}

bool Trapezoid::operator==(const Quadrilateral& other) const {
    if (other.getType() != "Trapezoid") return false;
    const Trapezoid& t = static_cast<const Trapezoid&>(other);
    return (getLength1() == t.getLength1() &&
            getLength2() == t.getLength2() &&
            getWidth1() == t.getWidth1());
}

Rectangle::Rectangle(double l, double w) : Trapezoid(l, l, w) {}

string Rectangle::getType() const { return "Rectangle"; }

void Rectangle::printInfo(ostream& os) const {
    os << "Rectangle:len=" << getLength1()
       << ",width=" << getWidth1()
       << ",area=" << getArea()
       << ",perimeter=" << getPerimeter();
}

bool Rectangle::operator==(const Quadrilateral& other) const {
    if (other.getType() != "Rectangle") return false;
    const Rectangle& r = static_cast<const Rectangle&>(other);
    return (getLength1() == r.getLength1() &&
            getWidth1() == r.getWidth1());
}

Square::Square(double s) : Rectangle(s, s) {}

string Square::getType() const { return "Square"; }

void Square::printInfo(ostream& os) const {
    os << "Square:side=" << getLength1()
       << ",area=" << getArea()
       << ",perimeter=" << getPerimeter();
}

bool Square::operator==(const Quadrilateral& other) const {
    if (other.getType() != "Square") return false;
    const Square& s = static_cast<const Square&>(other);
    return getLength1() == s.getLength1();
}    
