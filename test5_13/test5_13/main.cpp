#include <iostream>
using namespace std;

class date{
private:
    int d;
public:
    date(int dd = 0):d(dd)
    {}
    void show()const
    {
        cout << d << endl;
    }
    void setD(int dd)
    {
        d = dd;
    }
    int getD()const
    {
        return d;
    }
};
class mytest{
private:
    int x;
public:
    mytest(int xx)
    {
        x = xx;
    }
};

class test:public mytest{
private:
    int a, b;
    date c;
    static int count;
public:
    //构造函数
    test(int aa = 0,int bb = 0,int cc = 0)
    :a(aa), c(cc), mytest(cc)
    {
        a = aa;
        b = bb;
    }
    //拷贝构造
    test(const test& other):c(other.c),mytest(other)
    {
        a = other.a;
        b = other.b;
    }
    //析构函数
    ~test()
    {}
    void show()
    {
        cout << a << " " << b <<  " " << c.getD() << endl;
    }
    //getter
    int getA()const
    {
        return a;
    }
    int getB()const
    {
        return b;
    }
    date getDate()const
    {
        return c;
    }
    //setter
    void setA()
    {
        cin >> a;
    }
    void setB()
    {
        cin >> b;
    }
    void setDate()
    {
        int a;
        cin >> a;
        c.setD(a);
    }
};

int main()
{
    test a,b(1),c(3,4);
    test d(b);
    d.setA();
    d.setB();
    d.setDate();
    d.show();
    
    return 0;
}
