#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<stdlib.h>
const int INT_MIN = -2e31;
const int INT_MAX = 2e31 - 1;
enum State
{
    VAILD,
    INVAILD
}Sta = INVAILD;//创造变量默认为非法
int my_atoi(const char* str)
{
    assert(str);
    if (*str == '\0')
    {
        return 0;
    }
    while (isspace(*str))
    {
        str++;
    }
    int flag = 1;
    if (*str == '+')
    {
        flag = 1;
        str++;
    }
    else if (*str == '-')
    {
        flag = -1;
        str++;
    }
    long long ret = 0;
    while (*str != '\0')
    {
        if (isdigit(*str))
        {
            ret = ret * 10 + flag * (*str - '0');//减去字符0，才是数字0
            if (ret > INT_MAX || ret < INT_MIN)
            {
                return 0;
            }
        }
        else
        {
            return (int)ret;//强制类型转化为int（函数的返回值是int）
        }
        str++;
    }
    if (*str == '\0')
    {
        Sta = VAILD; //正常转换完了，到末尾的 \0
    }
    return (int)ret;




}
int main()
{
    char arr[20] = "1234";
    int ret = my_atoi(arr);
    if (Sta == VAILD)
    {
        printf("合法转换:%d\n", ret);
    }
    else if (Sta == INVAILD)
    {
        printf("非法转换:%d\n", ret);
    }
    return 0;
}

//#include <stdio.h>
//#include <math.h>
//
//int my_stoi(char* str)
//{
//    int count = 0;
//    int ret = 0;
//    char* p = str;
//    while(*p++) count++;
//    while(count)
//    {
//        ret += (*str - '0')*pow(10, count - 1);
//        str++;
//        count--;
//    }
//    return ret;
//}
//int main()
//{
//    char str[] = "12345";
//    printf("%d\n", my_stoi(str));
//    return 0;
//}
