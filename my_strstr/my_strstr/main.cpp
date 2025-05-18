#include <stdio.h>

char* my_strstr(const char* str1, const char* str2)
{
    char* p = (char*)str1;
    char* s1 = (char*)str1;
    char* s2 = (char*)str2;
    
    if(!*str2)
        return (char*)str1;
    while(*p)
    {
        s1 = p;
        s2 = (char*)str2;
        while(*s1 && *s2 && !(*s1-*s2))
        {
            s1++;
            s2++;
        }
        if(! *s2)
            return p;
        p++;
    }
    return (NULL);
}
int main()
{
    char str1[] = "hello";
    char str2[] = "aa";
    printf("%p\n", my_strstr(str1, str2));
    
    return 0;
}
