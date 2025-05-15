#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
//    char ch;
//    while(cin.get(ch))
//    {
//        cout.put(ch);
//    }
    
    char buf[110];
    cin.getline(buf, 90, EOF);
    cout << buf << endl;
    return 0;
}
