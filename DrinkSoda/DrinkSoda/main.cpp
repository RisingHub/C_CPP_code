#include <stdio.h>

int ret = 0;
int func(int n)
{
    if(n == 0) return 0;
    
    return n + func(n/2);
    
}
int main()
{
    int n = 4;
    printf("%d\n",func(n));
    
    
    return 0;
}
