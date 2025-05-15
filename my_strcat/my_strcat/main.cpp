#include <stdio.h>

char* my_strcat(char* dest, const char* source)
{
    char* ret = dest;
    while(*dest) dest++;
    
    while((*dest++ = *source++))
    {
        ;
    }
    return ret;
}
int main()
{
    char str1[] = "hello";
    char* str2 = "cpp";
    printf("%s\n", my_strcat(str1, str2));
    return 0;
}
