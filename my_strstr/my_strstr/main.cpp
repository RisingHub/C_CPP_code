#include <stdio.h>
#include <string.h>
char* my_strstr(const char* str1, const char* str2)
{
    char* pc = (char*)str1;
    char *s1, *s2;
    while(*pc)
    {
        s1 = pc;
        s2 = (char*)str2;
        
        while(*s1 == *s2 && *s1 && *s2)
        {
            s1++;
            s2++;
        }
        if(!*s2) return pc;
        
        pc++;
    }
    
    return (NULL);
}
int main()
{
    char str[] ="This is a simple string";
    char * pch;
    //找到simple位置
    pch = my_strstr (str,"simple");
    if (pch != NULL)
        strncpy (pch,"sample",6);//将simple用sample代替
    puts (str);
    return 0;
}
