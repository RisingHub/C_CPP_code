#include <stdio.h>

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year)
{
    return (year%4==0 &&year%100!=0) || (year%400==0);
}

int Get_Day(int year, int month)
{
    if(isLeapYear(year) && month == 2)
        return day[2]+1;
    else
        return day[month];
}
int main()
{
    int y = 0, m = 0;
    while(scanf("%d%d", &y, &m) != EOF)
    {
        printf("%d\n", Get_Day(y, m));
    }
    
    return 0;
}
