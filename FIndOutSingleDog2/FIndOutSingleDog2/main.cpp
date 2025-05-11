#include <stdio.h>

void solve(int arr[], int len)
{
    int i = 0;
    int cnt[1001] = {0};
    int flag[1001] = {0};
    for(i = 0; i < len; i++)
    {
        cnt[arr[i]]++;
    }
    
    for(i = 0; i < len; i++)
    {
        if(flag[arr[i]]==0 && cnt[arr[i]]==1)
        {
            printf("%d ", arr[i]);
            flag[arr[i]]=1;
        }
    }
}
int main()
{
    int arr[110] = {0};
    int n;
    scanf("%d", &n);
    
    int i = 0;
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    solve(arr, n);
    
    return 0;
}
