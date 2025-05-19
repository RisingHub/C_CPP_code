#include <stdio.h>
int check_sys()
{
    int i = 1;
    return (*(char *)&i);
}
int main()
{
    int ret = check_sys();
    if(ret == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    return 0;
}
//int isLittleEndian()
//{
//    int a = 0x11223344;
//    char* pa = (char*)&a;
//    if((int)*pa == 0x44)
//        return 1;
//    return 0;
//}
//
//int main()
//{
//    if(isLittleEndian())
//        printf("Little-Endian.\n");
//    else
//        printf("Big-Endian.\n");
//    return 0;
//}
