#include <stdio.h>
#include <string.h>
int cmp_int(const void* p1, const void* p2)
{
    return *((int*)p1) - *((int*)p2);
}

void _swap(void* p1, void *p2, size_t width)
{
    for(int i = 0; i < width; i++)
    {
        char tmp = *(((char*)p1)+i);
        *(((char*)p1)+i) = *(((char*)p2)+i);
        *(((char*)p2)+i) = tmp;
    }
}

void My_Bubble_Sort(void* base, size_t sz, size_t width,int (*cmp)(const void *p1, const void* p2))
{
    int i = 0;
    for(i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for(j = 0; j < sz - 1 - i; j++)
        {
            if(cmp((char*)base+j, (char*)base+(j+1)*width))
            {
                _swap((char*)base + j*width, (char*)base + (j+1)*width, width);
            }
        }
    }
}


void test_int()
{
    int arr[] = {9, 7, 4, 5, 6, 2, 0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    
    printf("The original arr is: ");
    int i = 0;
    for(i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }printf("\n");
    
    My_Bubble_Sort(arr, sz, sizeof(arr[0]), cmp_int);
    
    printf("The new arr is: ");
    for(i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }printf("\n");
}


int main()
{
    test_int();
    
    return 0;
}
