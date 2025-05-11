#include <stdio.h>

int Add(int a, int b)
{
    return a + b;
}
int Sub(int a, int b)
{
    return a - b;
}
int Mul(int a, int b)
{
    return a * b;
}
int Div(int a, int b)
{
    return a / b;
}

void menu()
{
    printf("****************************\n");
    printf("******1.Add    2.Sub********\n");
    printf("******3.Mul    4.Div********\n");
    printf("******   0.Exit     ********\n");
    printf("****************************\n");
}
int main()
{
    int input = 0;
    int (*p[5])(int, int) = {NULL, Add, Sub, Mul, Div};
    do{
        menu();
        printf("Please choose: ");
        scanf("%d", &input);
        if(input == 0)
        {
            printf("Exit.\n");
        }
        else if(input >= 1 && input <= 4)
        {
            printf("Please input operator numbers: ");
            int a = 0, b = 0;
            scanf("%d %d", &a, &b);
            int ans = p[input](a, b);
            printf("The result is %d.\n", ans);
        }
        else
        {
            printf("Input is Error.Please re-enter.\n");
        }
    }while(input);
    
    return 0;
}
