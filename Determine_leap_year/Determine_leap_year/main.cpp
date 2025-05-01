#include <stdio.h>

int LeapYear(int y);
int main()
{
    int n;
    printf("Please enter the year which you want to determine: \n");
    scanf("%d",&n);
    if(LeapYear(n)) printf("%d is LeapYear.\n", n);
    else printf("%d isn't LeapYear.\n", n);
    return 0;
}
int LeapYear(int y)
{
    if(((y%4==0) && (y%100!=0)) || (y%400==0))
        return 1;
    return 0;
}
