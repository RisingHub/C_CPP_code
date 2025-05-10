#include <stdio.h>
#include <string.h>

void Reverse(char* s)
{
    char* left = s;
    char* right = s + strlen(s) - 1;
    while(left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
int main()
{
    char s[10001] = {0};
    while(gets(s))
    {
        Reverse(s);
        printf("%s\n", s);
        memset(s, 0, sizeof(s)/sizeof(s[0]));
    }
    
    
    return 0;
}
