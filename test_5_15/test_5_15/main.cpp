#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Product{
private:
    char name[25];
    float price;
    int num;
public:
    Product(char* _name, float _price, int _num){
        strcpy(name, _name);
        price = _price;
        num = _num;
    }
    
};
class Store{
private:
    int count;
    Product* p;
public:
    Store(){
        
    }
    void addItem(){
        
    }
    void deleteItem(){
        
    }
    void editItem(){
        
    }
    void searchItem()const{
        
    }
};
int main()
{
    ofstream fout;
    fout.open("test.txt", ios::out);
    if(!fout)
    {
        cout << "Error, cannot open the file.\n";
        exit(1);
    }
    fout << setw(20) << "hello" << endl;
    fout << setw(20) << fixed << setprecision(3) << setfill('0') << 1.2345 << endl;
    fout << hex << 1000 << endl;
    fout <<
    while(1)
    {
        cout << "Please choose your operation: " << endl;
        cout << "[1]show; [2]add; [3]delete; [4]edit; [5]exit\n";
        int input = 0;
        cin >> input;
        switch(input)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
        }
    }
    return 0;
}
