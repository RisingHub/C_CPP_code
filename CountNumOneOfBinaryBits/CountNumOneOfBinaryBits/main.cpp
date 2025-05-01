#include <stdio.h>

int Cnt(int n)
{
    int cnt = 0;
    while(n)
    {
        n &= (n-1);
        cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", Cnt(n));
    return 0;
}
