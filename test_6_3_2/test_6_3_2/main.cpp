#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class QuadraticEquation{
private:
    double a;
    double b;
    double c;
public:
    QuadraticEquation(double _a=0, double _b=0, double _c=0)
    :a(_a), b(_b), c(_c){}
    
    double GetA()const{
        return a;
    }
    double GetB()const{
        return b;
    }
    double GetC()const{
        return c;
    }
    double getDiscriminant(){
        double delta = b*b - 4*a*c;
        return delta;
    }
    double getRoot1(){
        return (-b+sqrt(getDiscriminant()))/(2*a);
    }
    double getRoot2(){
        return (-b-sqrt(getDiscriminant()))/(2*a);
    }
    int getRootCount(){
        if(getDiscriminant() > 0){
            return 2;
        }else if(getDiscriminant() == 0){
            return 1;
        }else{
            return 0;
        }
    }
    void show(){
        if(a == 0){
            cout << "不是二次方程" << endl;
        }else{
            if(getRootCount() == 0){
                cout << "无实数根" << endl;
            }else if(getRootCount() == 1){
                cout << "一个实数根：" << fixed << setprecision(1) << getRoot1() << endl;
            }else{
                cout << "两个实数根：" << fixed << setprecision(1) << getRoot1() << " " << fixed << setprecision(1) << getRoot2() << endl;
            }
        }
    }
};
int main()
{
    double a = 0.0, b = 0.0, c = 0.0;
    cin >> a >> b >> c;
    QuadraticEquation q(a, b, c);
    q.show();
    
    return 0;
}
