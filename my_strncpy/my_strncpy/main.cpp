#include <stdio.h>
#include <assert.h>
char* my_strncpy(char* dest, const char* src, size_t num)
{
    char* ret = dest;
    assert(dest && src);
    
    int i = 0;
    for(i = 0; i < num && src[i]; i++)
    {
        dest[i] = src[i];
    }
    if(i < num)
    {
        dest[i] = 0;
    }
    return ret;
}
int main()
{
    char str1[20] = "hello";
    char str2[] = "cpp";
    my_strncpy(str1, str2, 3);
    printf("%s\n", str1);
    return 0;
}
