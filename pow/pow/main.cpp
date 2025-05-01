#include <stdio.h>

int _pow(int n, int k)
{
    
    if(k == 1) return n;
    return _pow(n,k-1)*n;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", _pow(n,k));
    
    
    return 0;
}
