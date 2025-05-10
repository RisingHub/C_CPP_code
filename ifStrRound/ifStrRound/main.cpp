#include <stdio.h>
#include <string.h>
int ifRound(char* p1, char* p2, int len1, int len2)
{
    if(len1 != len2)
    {
        return 0;
    }
    
    for(int i = 0; i < len1; i++)
    {
        char tmp = p1[0];
        for(int j = 0; j < len1 - 1; j++)
        {
            p1[j] = p1[j+1];
        }
        p1[len1-1] = tmp;
        if(strcmp(p1, p2) == 0)
        {
            return i;
            break;
        }
    }
    return 0;
}
int main()
{
    char s1[110], s2[110];
    while(scanf("%s %s", s1, s2) != EOF)
    {
        
        int len1 = (int)strlen(s1);
        int len2 = (int)strlen(s2);
        int ans = ifRound(s1, s2, len1, len2);
        if(ans == 0)
        {
            printf("s1 cannot become s2 by left or right rounding.\n");
        }
        else if(ans > len1/2)
        {
            printf("s1 right move %d chars will become s2.\n", len1-ans);
        }
        else
        {
            printf("s1 left move %d chars will become s2.\n", ans);
        }
        memset(s1, 0 , sizeof(s1));
        memset(s2, 0 , sizeof(s2));
    }
    
    
    return 0;
}
