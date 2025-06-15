#include <iostream>

using namespace std;

 

class Base1 {

protected:

    int data1;

public:

    Base1(int a = 0) {

        data1 = a;

        cout << "Base Constructor1\n";

    }

    ~Base1() {

        cout << "Base Destructor1\n";

    }

};

 

class Base2 {

protected:

    int data2;

public:

    Base2(int a = 0) {

        data2 = a;

        cout << "Base Constructor2\n";

    }

    ~Base2() {

        cout << "Base Destructor2\n";

    }

};

 

class Derived: public Base1, public Base2  {

    int d;

public:
    Derived(int a = 0, int b = 0, int c = 0)
    :Base1(a), Base2(b), d(c)
    {
        cout << "Derived Constructor\n";
    }

         //在此处完成Derived类构造函数的定义，构造函数包含3个形参



    ~Derived() {

        cout << "Derived Destructor\n";

    }

    void Show() {

        cout << data1 << "," << data2 << "," << d << endl;
        //完成此函数的定义，输出Derived的所有数据成员的值，格式见输出样例
        
    }

};

 

int main() {

    int x, y, z;

    cin >> x >> y >> z;

    Derived c(x, y, z);

    c.Show();

}
