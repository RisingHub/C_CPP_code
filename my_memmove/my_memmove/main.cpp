#include <stdio.h>
#include <assert.h>

void* my_memmove(void* dest, const void* src, size_t num)
{
    char* ret = (char*)dest;
    assert(dest && src);
    
    if(dest <= src)
    {
        while(num--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    else
    {
        dest = (char*)dest + num - 1;
        src = (char*)src + num - 1;
        while(num--)
        {
            *((char *)dest + num) = *((char *)src + num);
            dest = (char *)dest + num;
            src = (char *)src + num;
        }
    }
    
    return ret;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    my_memmove(arr, arr+2, 12);
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    
    
    return 0;
}
