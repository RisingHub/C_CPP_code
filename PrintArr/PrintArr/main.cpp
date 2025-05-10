#include <stdio.h>

void PrintArr(int* p, int len)
{
    for(int i = 0 ; i < len ;i++)
    {
        printf("%d ", *(p+i));
    }
    printf("\n");
}
int main()
{
    int a[110];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    PrintArr(a, n);
    
    return 0;
}
