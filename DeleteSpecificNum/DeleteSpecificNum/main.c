#include <stdio.h>

void Delete(int arr[], int n, int x)
{
    int i = 0;
    
    for(i = 0; i < n; i++)
    {
        if(arr[i] == x) continue;
        printf("%d ", arr[i]);
    }
}
int main(void)
{
    int n = 0;
    int arr[50] = {0};
    scanf("%d", &n);
    int i = 0;
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);
    int x; scanf("%d", &x);
    Delete(arr, n, x);
    return 0;
}
