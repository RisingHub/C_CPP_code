#include <stdio.h>

void GetOddBits(int n)
{
    printf("Odd Bits:\n");
    for(int i = 30; i >= 0; i -= 2)
    {
        printf("%d ", (n>>i)&1);
    }
    printf("\n\n");
}
void GetEvenBits(int n)
{
    printf("Even Bits:\n");
    for(int i = 31; i >= 1; i -= 2)
    {
        printf("%d ", (n>>i)&1);
    }
    printf("\n\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    GetOddBits(n);
    GetEvenBits(n);
    
    return 0;
}
