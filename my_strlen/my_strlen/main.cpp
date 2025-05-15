#include <stdio.h>

size_t my_strlen(const char* pc)
{
    if(*pc == 0)
        return 0;
    return my_strlen(pc+1) + 1;
    
}
int main()
{
    char arr[] = "hello cpp.";
    printf("my_strlen(arr) = %zu\n", my_strlen(arr));
    
    return 0;
}
