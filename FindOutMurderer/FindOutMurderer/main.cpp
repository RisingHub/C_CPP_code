#include <stdio.h>

//1:表示是凶手
//0:表示不是凶手
int a[4];
// 0  1  2  3
// a  b  c  d
int main()
{
    int i = 0;
    for(i = 0; i < 4; i++)
    {
        //假设都是真话
        a[0] = 0;
        a[2] = 1;
        a[3] = 1;
        a[3] = 0;
        //假设第i个人说了假话
        a[i] ~= a[i];
        
    }
    
    
}
