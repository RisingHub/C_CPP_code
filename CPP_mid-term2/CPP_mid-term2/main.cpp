#include <iostream>

using namespace std;

class Num{

protected:

    double real;

public:

    Num(double r = 0)//默认值的构造函数
    :real(0)
    {}
    Num(const Num& other)             //拷贝构造函数，新对象real为实参对象real*2
    {
        real = other.real*2;
    }
    void add(const Num& other)        //输出两real之和
    {
        printf("对象之和: %g\n", real + other.real);
    }
    void set()       //键盘输入修改real
    {
        double r = 0;
        cin >> r;
        real = r;
    }
    void print()     //输出整数.
    {
        printf("%g\n", real);
    }
};

class Complex: public Num{

protected:

    double imag;

public:

    Complex(double r = 0, double i = 0)      //第一个参数传递给基类，第二个参数初始化imag
    :Num(r), imag(i){}
    Complex(const Complex& other)   //拷贝构造函数，imag为原对象imag*2
    {
        Num(other.real);
        imag = other.imag*2;
    }
    void set()                               //键盘修改real和imag
    {
        double r, i;
        cin >> r >> i;
        real = r;
        imag = i;
    }
    void add(const Complex& other)   //输出两复数之和
    {
        real += other.real;
        imag += other.imag;
        if(imag == 0)
        {
            printf("对象之和: %g\n", real);
        }
        else
        {
            if(imag < 0)
            {
                printf("对象之和: %g%gi\n", real, imag);
            }
            else
            {
                printf("对象之和: %g+%gi\n", real, imag);
            }
        }
    }
    void print()                         //输出复数实部和虚部
    {
        if(imag == 0)
        {
            printf("%g\n", real);
        }
        else
        {
            if(imag < 0)
            {
                printf("%g%gi\n", real, imag);
            }
            else
            {
                printf("%g+%gi\n", real, imag);
            }
        }
    }
};
int main()
{
    Complex c1;
    c1.set();
    Complex c2(c1);
    c1.print();
    c2.print();
    c1.add(c2);
    return 0;
}
