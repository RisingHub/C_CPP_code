#include <stdio.h>

int sum(int a)
{
    int t = a;
    int ret = 0;
    for(int i = 1;i <= 5; i++)
    {
        ret += t;
        t = t*10 + a;
    }
    return ret;
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d\n", sum(a));
    
    return 0;
}
