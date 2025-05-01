#include <stdio.h>
#include <math.h>

int NumLen(int n)
{
    int ret = 0;
    do{
        n /= 10;
        ret++;
    }while(n);
    return ret;
}
void Print(int n)
{
    if(n <= 9){
        printf("%d\n", n);
        return;
    }
    
    int len = NumLen(n);
    int k = pow(10,len-1);
    printf("%d ",n/k);
    Print(n%k);
    
}
int main()
{
    int n;
    scanf("%d", &n);
    Print(n);
    return 0;
}
