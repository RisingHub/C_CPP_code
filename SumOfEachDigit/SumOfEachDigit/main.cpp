#include <stdio.h>

int sum(int n)
{
    if(n == 0) return 0;
    return sum(n/10) + n%10;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", sum(n));
    
    return 0;
}
