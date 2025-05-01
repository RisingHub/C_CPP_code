#include <stdio.h>

//非递归
int main()
{
    int n;
    scanf("%d", &n);
    int a = 1,b = 0, c = 0;
    for(int i = 1; i <= n ;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("%d\n", c);
    
    return 0;
}
////递归
//int Fib(int n)
//{
//    if(n == 1 || n == 2)
//    {
//        return 1;
//    }
//    else
//    {
//        return Fib(n-1) + Fib(n-2);
//    }
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", Fib(n));
//    
//    return 0;
//}
