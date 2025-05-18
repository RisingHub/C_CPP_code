#include <stdio.h>
#include <assert.h>
int my_strcmp(const char* str1, const char* str2)
{
    assert(str1 && str2);
    while(*str1 == *str2)
    {
        if(*str1 == '\0')
            return 0;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
int main()
{
    char str1[] = "abcdef";
    char str2[] = "abcdee";
    if(my_strcmp(str1, str2) > 0)
    {
        printf("s1 > s2\n");
    }
    else if(!my_strcmp(str1, str2))
    {
        printf("s1 = s2\n");
    }
    else
    {
        printf("s1 < s2\n");
    }
    
    return 0;
}
