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
int main()
{
    Num n1;
    n1.set();
    Num n2(n1);
    n1.print();
    n2.print();
    n1.add(n2);
    return 0;
}
