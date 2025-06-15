#include <iostream>
#include <stdio.h>
using namespace std;

class A {
public:
    void Fun(){
        cout << "A::Fun" <<endl;
    }
    virtual void Do(){
        cout << "A::Do" << endl;
    }
    
};

class B:public A {
public:
    void Do(){ cout << "B::Do" << endl;}
};

class C:public B {
public:
    void Do( ){ cout << "C::Do" << endl; }
    void Fun(){ cout << "C::Fun" << endl;}
};
void Call(A* p)
{
    p->Fun();
    p->Do();
}
int main()
{
    Call( new A() );
    Call( new C() );
    return 0;
}
