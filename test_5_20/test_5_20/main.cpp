#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
class Product{
private:
    char name[20];
    float price;
    int num;
public:
    Product(char* _name, float _price = 0, int _num = 0)
    {
        strcpy(name, _name);
        price = _price;
        num = _num;
    }
    void show(ostream& out)const{
        out << setw(10) << name << setw(10) << setprecision(4) << price << setw(10) << num << endl;
    }
    friend istream& operator>>(istream& in, Product& pro);
};
ostream& operator<<(ostream& out, const Product& pro)
{
    pro.show(out);
    return out;
}
istream& operator>>(istream& in, Product& pro)
{
    in >> pro.name >> pro.price >> pro.num;
    return in;
}
int main()
{
    ofstream fout("store.text");
    if(!fout)
    {
        cout << "can't open the file.\n";
        exit(1);
    }
    Product pro("apple", 3.4, 12);
    fout << pro;
    fout.close();
    cout << pro;
    return 0;
}
