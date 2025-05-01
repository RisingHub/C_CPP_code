#include <stdio.h>

int main()
{
    int n;
    printf("Plaese enter the rows or columns of the table: \n");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=i;j++)
        {
            printf("%d*%d=%-3d",j,i,i*j);
        }
        printf("\n");
    }
    
    
    return 0;
}
