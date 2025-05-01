#include <stdio.h>

int arr[110];
int n;
void init()
{
    for(int i = 1;i<=n;i++) arr[i] = 0;
}
void print()
{
    for(int i = 1;i<=n;i++) printf("%d ", arr[i]);
    printf("\n");
}
void reverse()
{
    for(int i = 1;i<=n/2;i++)
    {
        int t = arr[i];
        arr[i] = arr[n-i+1];
        arr[n-i+1] = t;
    }
}
int main()
{
    printf("Please enter the length of arr: \n");
    scanf("%d", &n);
    
    init();
    printf("arr after init: ");
    print();
    
    printf("Please enter the arr: \n");
    for(int i = 1;i<=n;i++)
    {
        scanf("%d", &arr[i]);
    }

    
    reverse();
    printf("arr after reverse: ");
    print();
    
    
    
    return 0;
}

