#include <stdio.h>

//非递归
int main()
{
    int n;
    scanf("%d", &n);
    int t = 1;
    for(int i = 1; i <= n; i++)
    {
        t *= i;
    }
    printf("%d\n", t);
    
    return 0;
}
////递归
//int Fac(int n)
//{
//    if(n == 1) return 1;
//    return n * Fac(n-1);
//}
//int main()
//{
//    int n;
//    scanf("%d", &n);
//    printf("%d\n", Fac(n));
//    
//    
//    return 0;
//}
