#include <stdio.h>

int main()
{
    double sum = 0;
    int n = 10;
    for(int i = 1; i<=n;i++)
    {
        int x; scanf("%d", &x);
        sum += x;
    }
    printf("%f", sum/10);
    return 0;
}
