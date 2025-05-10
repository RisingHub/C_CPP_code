#include <stdio.h>

void Bubble_Sort(int* p,int len)
{
    for(int i = 0 ; i < len - 1; i++)
    {
        for(int j = 0; j < len - 1 - i; j++)
        {
            if(p[j] > p[j+1])
            {
                int tmp = p[j];
                p[j] = p[j+1];
                p[j+1] = tmp;
            }
        }
    }
}
int main()
{
    int n;
    int a[110];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    Bubble_Sort(a, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
