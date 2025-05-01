#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("Before Swap:\na: %d, b: %d\n",a,b);
    a = a^b;
    b = a^b;
    a = a^b;
    printf("After Swap:\na: %d, b: %d\n",a,b);
    
    return 0;
}
