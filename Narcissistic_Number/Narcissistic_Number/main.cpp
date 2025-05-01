#include <stdio.h>
#include <math.h>

int NumLen(int n)
{
    int len = 0;
    do{
        n/=10;
        len++;
    }while(n);
    return len;
}
int ifNar(int n)
{
    int k = NumLen(n);
    int t = n;
    int ret = 0;
    do{
        ret += pow(t%10, k);
        t /= 10;
    }while(t);
    if(ret == n) return 1;
    else return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    if(ifNar(n)) printf("%d is a Narcissistic Number.\n", n);
    else printf("%d isn't a Narcissistic Number.\n",n);
    
    return 0;
}
