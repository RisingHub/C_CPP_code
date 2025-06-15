#include <iostream>

using namespace std;
class Base1 {

protected:

    int data1;

public:

    Base1(int a = 8) {

        data1 = a;

        cout << data1 << ", Base Constructor1\n";

    }

    ~Base1() {

        cout << data1 << ", Base Destructor1\n";

    }

};



class Base2 {

protected:

    int data2;

public:

    Base2(int a = 9) {

        data2 = a;

        cout << data2 << ", Base Constructor2\n";

    }

    ~Base2() {

        cout << data2 << ", Base Destructor2\n";

    }

};



class Derived: public Base1, public Base2 {

    int d;

    Base1 b1;

    Base2 b2;

public:

    //在此处完成Derived类构造函数的撰写，构造函数有三个形参；
    Derived(int d1 = 0, int d2 = 0, int d3 = 0)
    :Base1(d1)
    ,Base2(d2)
    ,d(d3)
    ,b1(d1+d2)
    ,b2(d1+d3)
    {
        
        cout << "Derived Constructor\n";
    }
     

 

    ~Derived() {

        cout << "Derived Destructor\n";

    }

    void Show() {

         //在此处完成Show函数的定义；
        cout << data1 << "," << data2 << "," << d << endl;
    }

};


int main(){
    int x, y, z;

    // cout << "Enter three integers for Derived class constructor parameters: ";

    cin >> x >> y >> z;

    Derived c(x, y, z);

    c.Show();
    return 0;
}
