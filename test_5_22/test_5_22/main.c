#include <stdio.h>
struct S
{
    int a:3;
    int b:4;
    int c:5;
    int d:4;
};

int main(void)
{
    struct S s = {0};
    //scanf("%d", &s.b);//error
    
    int b = 0;
    scanf("%d", &b);
    s.b = b;
    return 0;
}
