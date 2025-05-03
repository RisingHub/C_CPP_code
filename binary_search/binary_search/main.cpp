#include <stdio.h>

int a[110];
int bin_search(int arr[],int left,int right,int key);
int main()
{
    int n,k;
    printf("Please input the length of arr and the key num: \n");
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The key num is in the %dth of arr.\n",bin_search(a,1,n,k));
    //.
    
    return 0;
}
int bin_search(int arr[],int left,int right,int key)
{
    while(left <= right)
    {
        int mid = (left+right)/2;
        if(arr[mid] > key)
        {
            right = mid-1;
        }
        else if(arr[mid] < key)
        {
            left = mid +1;
        }
        else
        {
            return mid;
        }
    }
    
    return -1;
}
