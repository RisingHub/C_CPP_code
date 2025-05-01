#include <stdio.h>

int GetCnt(int n, int m)
{
    int t = (n^m);
    int cnt = 0;
    while(t)
    {
        t &= (t-1);
        cnt++;
    }
    return cnt;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", GetCnt(n, m));
    return 0;
}
