#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* source)
{
    char* ret = dest;
    assert(dest!=NULL && source!=NULL);
    while((*dest++ = *source++))
    {
        ;
    }
    return ret;
}
int main()
{
    char str[10] = {0};
    my_strcpy(str, "hello");
    printf("%s\n", str);
    
    return 0;
}
