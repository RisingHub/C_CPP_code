#include <stdio.h>

int int_cmp(const void* p1, const void* p2)
{
    //默认比较函数前面的数据大于后面的数据的时候，排列是从小到大的顺序，反之，从大到小排列
    return (*(int*)p1 - *(int*)p2);
}

//冒泡排序中的交换函数，实现两个元素位置的交换，因为数据类型未知，注意要传数据类型的大小
void _swap(void* p1, void* p2, size_t width)
{
    int i = 0;
    for(i = 0; i < width; i++)
    {
        //先把void*类型的指针强转成一个字节的char*类型，再通过数据类型的大小，分别交换每一个内存单元上对应的内容
        char tmp = *((char*)p1 + i);
        *((char*)p1 + i) = *((char*)p2 + i);
        *((char*)p2 + i) = tmp;
    }
}

//由于要满足各种类型数据的排列，所以形参类型注意用void
void bubble_sort(void* base, size_t sz, size_t width, int (*cmp)(const void *p1, const void *p2))
{
    int i = 0, j = 0;
    //一共要排序多少轮
    for(i = 0; i < sz - 1; i++)
    {
        //每一轮要比较多少次
        for(j = 0; j < sz-1-i; j++)
        {
            if(cmp((char*)base + j*width, (char*)base + (j+1)*width) > 0)
            {
                _swap((char*)base + j*width, (char*)base + (j+1)*width, width);
            }
        }
    }
    
}
int main()
{
    //以整型数组为例
    int arr[] = {6, 1, 7, 9, 2, 4, 3, 0};
    int i = 0;
    bubble_sort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), int_cmp);
    for(i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
