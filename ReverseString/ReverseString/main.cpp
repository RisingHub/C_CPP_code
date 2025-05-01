#include <stdio.h>
#include <string.h>
const int N = 1e4 + 10;
int main()
{
    char a[N] = {0};
    scanf("%[^\n]s", a);
    int sz = strlen(a);
    for(int i = sz - 1; i >= 0; i--)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}
