#include <iostream>
#include <cmath>
#include <algorithm>
#define PI 3.14

using namespace std;

class Shape {
public:
    virtual void inputInfo(istream &in) = 0;
    virtual void show(ostream &out) const = 0;
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
protected:
    double length, width;
public:
    Rectangle(double length = 0, double width = 0) : length(length), width(width) {}
    void inputInfo(istream &in) override {
        in >> length >> width;
    }
    void show(ostream &out) const override {
        out << "rectangle:length=" << length << ",width=" << width << ",area=" << getArea();
    }
    double getArea() const override {
        return length * width;
    }
};

class Square : public Rectangle {
public:
    Square(double side = 0) : Rectangle(side, side) {}
    void inputInfo(istream &in) override {
        double side;
        in >> side;
        length = width = side;
    }
    void show(ostream &out) const override {
        out << "square:side=" << length << ",area=" << getArea();
    }
};

class Circle : public Shape {
private:
    double r;
public:
    Circle(double r = 0) : r(r) {}
    void inputInfo(istream &in) override {
        in >> r;
    }
    void show(ostream &out) const override {
        out << "circle:radius=" << r << ",area=" << getArea();
    }
    double getArea() const override {
        return PI * r * r;
    }
};

class Triangle : public Shape {
private:
    double side1, side2, side3;
public:
    Triangle(double s1 = 0, double s2 = 0, double s3 = 0) : side1(s1), side2(s2), side3(s3) {}
    void inputInfo(istream &in) override {
        in >> side1 >> side2 >> side3;
    }
    void show(ostream &out) const override {
        out << "triangle:side1=" << side1 << ",side2=" << side2 << ",side3=" << side3 << ",area=" << getArea();
    }
    double getArea() const override {
        double p = (side1 + side2 + side3) / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
};

istream& operator>>(istream& in, Shape& s) {
    s.inputInfo(in);
    return in;
}

ostream& operator<<(ostream& out, const Shape& s) {
    s.show(out);
    return out;
}

bool operator<(const Shape& s1, const Shape& s2) {
    return s1.getArea() < s2.getArea();
}

bool compare(Shape* a, Shape* b) {
    return *a < *b;
}

int main() {
    int n;
    char c;
    cin >> n;
    Shape **p = new Shape*[n];

    for(int i = 0; i < n; i++) {
        cin >> c;
        switch(c) {
            case 'r':
                p[i] = new Rectangle();
                break;
            case 's':
                p[i] = new Square();
                break;
            case 'c':
                p[i] = new Circle();
                break;
            case 't':
                p[i] = new Triangle();
                break;
        }
        cin >> (*p[i]);
    }

    sort(p, p + n, compare);

    for(int i = 0; i < n; i++) {
        cout << *p[i] << endl;
    }

    for(int i = 0; i < n; i++) {
        delete p[i];
    }
    delete [] p;
    return 0;
}
    

