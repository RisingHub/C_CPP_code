#include <stdio.h>
#include <assert.h>
char* my_strncat(char* dest, const char* src, size_t num)
{
    char* ret = dest;
    assert(*dest && *src);
    while(*dest)
    {
        dest++;
    }
    while(num-- && *src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;
    return ret;
}
int main()
{
    char str1[] = "hello";
    char str2[] = "cppp";
    printf("%s\n", my_strncat(str1, str2, 3));
    return 0;
}
