#include <stdio.h>

int is_prime(int n);
int main()
{
    int n;
    printf("Please enter the num you want to determine: \n");
    scanf("%d",&n);
    if(is_prime(n)) printf("%d is prime number.\n",n);
    else printf("%d isn't prime number.\n",n);
    return 0;
}
int is_prime(int n)
{
    if(n <= 1)
        return 0;
    for(int i = 2;i <= n/i;i++)
    {
        if(n%i == 0) return 0;
    }
    return 1;
}
