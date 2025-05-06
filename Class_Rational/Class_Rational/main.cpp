#include <iostream>
#include <algorithm>
using namespace std;
class Rational {
private:
    int numerator;
    int denominator;
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int num, int den) {
        
        int common = gcd(abs(num), abs(den));
        if((num<0&&den>0) || (num>0&&den<0))
        {
            numerator = abs(num)/common*(-1);
            denominator = abs(den)/common;
        }
        else
        {
            numerator = abs(num)/common;
            denominator = abs(den)/common;
        }
            
    }

    Rational(int num) : numerator(num), denominator(1) {}

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int num) {
        numerator = num;
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
    }

    void setDenominator(int den) {
        
        denominator = den;
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
    }

    int compareTo(const Rational& other) const {
        int left = numerator * other.denominator;
        int right = other.numerator * denominator;
        if (left > right) return 1;
        if (left < right) return -1;
        return 0;
    }

    bool equals(const Rational& other) const {
        return compareTo(other) == 0;
    }

    int& operator[](int index) {
        if (index == 0) return numerator;
        return denominator;
    }

    Rational& operator++() {
        numerator += denominator;
        return *this;
    }

    Rational& operator--() {
        numerator -= denominator;
        return *this;
    }

    Rational operator++(int) {
        Rational temp = *this;
        ++(*this);
        return temp;
    }

    Rational operator--(int) {
        Rational temp = *this;
        --(*this);
        return temp;
    }

    Rational operator-() {
        return Rational(-numerator, denominator);
    }

    Rational& operator+=(const Rational& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        numerator *= other.denominator;
        denominator *= other.numerator;
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
        if(denominator == -1)
        {
            denominator = 1;
            numerator *= -1;
        }
        return *this;
    }

    operator double() {
        return static_cast<double>(numerator) / denominator;
    }
};

Rational operator+(const Rational& a, const Rational& b) {
    Rational result = a;
    result += b;
    return result;
}

Rational operator-(const Rational& a, const Rational& b) {
    Rational result = a;
    result -= b;
    return result;
}

Rational operator*(const Rational& a, const Rational& b) {
    Rational result = a;
    result *= b;
    return result;
}

Rational operator/(const Rational& a, const Rational& b) {
    Rational result = a;
    result /= b;
    return result;
}

bool operator<(const Rational& a, const Rational& b) {
    return a.compareTo(b) < 0;
}

bool operator<=(const Rational& a, const Rational& b) {
    return a.compareTo(b) <= 0;
}

bool operator>(const Rational& a, const Rational& b) {
    return a.compareTo(b) > 0;
}

bool operator>=(const Rational& a, const Rational& b) {
    return a.compareTo(b) >= 0;
}

bool operator==(const Rational& a, const Rational& b) {
    return a.equals(b);
}

bool operator!=(const Rational& a, const Rational& b) {
    return !a.equals(b);
}

ostream& operator<<(ostream& os, const Rational& r) {
    if (r.getDenominator() == 1) {
        os << r.getNumerator();
    } else {
        os << r.getNumerator() << "/" << r.getDenominator();
    }
    return os;
}

istream& operator>>(istream& is, Rational& r) {
    int num, den;
    is >> num >> den;
    r = Rational(num, den);
    return is;
}

int main() {
    int num1, den1, num2, den2;
    cin >> num1 >> den1 >> num2 >> den2;
    Rational r1(num1, den1);
    Rational r2(num2, den2);

    cout << "The value of " << r1 <<" is " << double(r1) << "." << endl;
    cout << "The value of " << r2 <<" is " << double(r2) << "." << endl;

    if(r1 > r2)
    {
        cout << "(" << r1 << ")" << ">(" << r2 << ")" <<" is "<<"true.\n";
    }
    else
    {
        cout << "(" << r1 << ")" << ">(" << r2 << ")" <<" is "<<"false.\n";
    }
    
    if(r1 >= r2)
    {
        cout << "(" << r1 << ")" << "=>(" << r2 << ")" <<" is "<<"true.\n";
    }
    else
    {
        cout << "(" << r1 << ")" << "=>(" << r2 << ")" <<" is "<<"false.\n";
    }
    
    if(r1 < r2)
    {
        cout << "(" << r1 << ")" << "<(" << r2 << ")" <<" is "<<"true.\n";
    }
    else
    {
        cout << "(" << r1 << ")" << "<(" << r2 << ")" <<" is "<<"false.\n";
    }
    
    if(r1 <= r2)
    {
        cout << "(" << r1 << ")" << "<=(" << r2 << ")" <<" is "<<"true.\n";
    }
    else
    {
        cout << "(" << r1 << ")" << "<=(" << r2 << ")" <<" is "<<"false.\n";
    }
    
    if(r1 == r2)
    {
        cout << "(" << r1 << ")" << "==(" << r2 << ")" <<" is "<<"true.\n";
    }
    else
    {
        cout << "(" << r1 << ")" << "==(" << r2 << ")" <<" is "<<"false.\n";
    }
    
    if(r1 != r2)
    {
        cout << "(" << r1 << ")" << "!=(" << r2 << ")" <<" is "<<"true.\n";
    }
    else
    {
        cout << "(" << r1 << ")" << "!=(" << r2 << ")" <<" is "<<"false.\n";
    }
    
    cout << "(" << r1 << ")" << "+" << "(" << r2 << ")" << "=" << r1 + r2 << endl;
    cout << "(" << r1 << ")" << "-" << "(" << r2 << ")" << "=" << r1 - r2 << endl;
    cout << "(" << r1 << ")" << "*" << "(" << r2 << ")" << "=" << r1 * r2 << endl;
    cout << "(" << r1 << ")" << "/" << "(" << r2 << ")" << "=" << r1 / r2 << endl;
    cout << "-(" << r1 << ")" << "=" << -r1 << "\n";
    cout << "-(" << r2 << ")" << "=" << -r2 << "\n";
    
    cout << "(" << r1 << ")[0]=" << r1[0] << endl;
    cout << "(" << r1 << ")[1]=" << r1[1] << endl;
    cout << "(" << r2 << ")[0]=" << r2[0] << endl;
    cout << "(" << r2 << ")[1]=" << r2[1] << endl;

    cout << "++(" << r1 << ")=" << ++r1 << endl;
    cout << "(" << r1 << ")++=" << r1++ << endl;
    cout << "--(" << r1 << ")=" << --r1 << endl;
    cout << "(" << r1 << ")--=" << r1-- << endl;

    cout << "++(" << r2 << ")=" << ++r2 << endl;
    cout << "(" << r2 << ")++=" << r2++ << endl;
    cout << "--(" << r2 << ")=" << --r2 << endl;
    cout << "(" << r2 << ")--=" << r2-- << endl;
    return 0;
}
