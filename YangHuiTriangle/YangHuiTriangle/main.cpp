#include <stdio.h>

int main()
{
    int n = 0;
    int a[25][25] = {0};
    scanf("%d", &n);
    int i = 0;
    for(i = 1; i <= n ; i++)
    {
        int j = 0;
        for(j = 1; j <= i; j++)
        {
            if(j == 1 || j == i)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
