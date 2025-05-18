#include <stdio.h>

void* my_memcpy(void* dest, const void* src, size_t num)
{
    char* ret = (char*)dest;
    while(num-- && (char*)src)
    {
        *(char*)dest = *(char*)src;
        dest = (char*)dest + 1;
        src = (char*)src + 1;
    }
    return ret;
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {5, 6, 7, 8, 9};
    my_memcpy(arr1, arr2, 12);
    int i = 0;
    for(i = 0; i< 5; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}
