#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu{
    char name[20];
    int age;
};

int cmp_int(const void* p1, const void* p2)
{
    return *((int*)p1) - *((int*)p2);
}

int cmp_stu_name(const void* p1, const void* p2)
{
    return strcmp(((struct Stu*)p1)->name, ((struct Stu*)p2)->name);
}

int cmp_stu_age(const void* p1, const void* p2)
{
    return ((struct Stu*)p1)->age > ((struct Stu*)p2)->age;
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
    
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    
    printf("The new arr is: ");
    for(i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }printf("\n");
}

void test_stu_name()
{
    struct Stu arr[3]={{"LiSi", 18}, {"ZhangSan", 27}, {"WangWu", 15}};
    printf("The original Student List is: \n");
    int i = 0;
    for(i = 0; i < 3; i++)
    {
        printf("%s=%d\n", arr[i].name, arr[i].age);
    }
    
    qsort(arr, 3, sizeof(struct Stu), cmp_stu_name);
    printf("The new Student List is: \n");
    for(i = 0; i < 3; i++)
    {
        printf("%s=%d\n", arr[i].name, arr[i].age);
    }
    
}

void test_stu_age()
{
    struct Stu arr[3]={{"LiSi", 18}, {"ZhangSan", 27}, {"WangWu", 15}};
    printf("The original Student List is: \n");
    int i = 0;
    for(i = 0; i < 3; i++)
    {
        printf("%s=%d\n", arr[i].name, arr[i].age);
    }
    
    qsort(arr, 3, sizeof(struct Stu), cmp_stu_age);
    printf("The new Student List is: \n");
    for(i = 0; i < 3; i++)
    {
        printf("%s=%d\n", arr[i].name, arr[i].age);
    }
}

int main()
{
    //test_int();
    //test_stu_name();
    test_stu_age();
    return 0;
}
