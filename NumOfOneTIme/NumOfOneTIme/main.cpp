#include <stdio.h>

int n;
int main()
{
    scanf("%d", &n);
    int ret = 0;
    for(int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        ret ^= x;
        
    }
    
    printf("%d\n",ret);
    
    
    
    return 0;
}
