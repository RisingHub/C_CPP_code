#include <stdio.h>

int main()
{
    int a[110], b[110];
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i =1;i<=n;i++)
    {
        int t=a[i];
        a[i]=b[i];
        b[i]=t;
    }
    printf("a: ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nb: ");
    for(int i=1;i<=n;i++)
    {
        printf("%d ",b[i]);
    }
    
    return 0;
}
