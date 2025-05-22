#include <stdio.h>

int check_sys(void)
{
    union{
        int i;
        char c;
    }un;
    un.i = 1;
    return un.c;
}
int main(void)
{
    if(check_sys() == 1)
    {
        printf("Little—endian storage.\n");
    }
    else
    {
        printf("Big—endian storage.\n");
    }
    
    return 0;
}
