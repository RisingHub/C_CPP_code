#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//void test1(void)
//{
//    int* p = (int*)malloc(sizeof(int)*5);
//    if(!p)
//    {
//        perror("malloc");
//        return 1;
//    }
//    else
//    {
//        
//    }
//    
//}
int main(void)
{
    //test_calloc
    int* p = (int*)malloc(sizeof(int)*5);
//    int* p = (int*)malloc(sizeof(int)*INT64_MAX);
    if(!p)
    {
        perror("calloc");
        return 1;
    }
    else
    {
        int i = 0;
        for(i = 0; i < 5; i++)
        {
            p[i] = i + 1;
        }
        p = NULL;
        free(p);
    }
    
    
//    //test_malloc
////    int* p = (int*)malloc(sizeof(int)*5);
//    int* p = (int*)malloc(sizeof(int)*INT64_MAX);
//    if(!p)
//    {
//        perror("malloc");
//        return 1;
//    }
//    else
//    {
//        int i = 0;
//        for(i = 0; i < 5; i++)
//        {
//            p[i] = i+1;
//        }
//    }
    
    return 0;
}
