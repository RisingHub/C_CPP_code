#include <stdio.h>

void Print(int n)
{
    int k = (13-n)/2;
    for(int i = 1; i <= k; i++) printf(" ");
    for(int i = 1; i <= n; i++) printf("*");
    for(int i = 1; i <= k; i++) printf(" ");printf("\n");
    if(n == 13) return;
    
    Print(n+2);
    for(int i = 1;i <= k; i++) printf(" ");
    for(int i = 1; i<= n; i++) printf("*");
    for(int i = 1;i <= k; i++) printf(" ");printf("\n");
    return;
}

int main()
{
    
    Print(1);
    
    
    return 0;
}
