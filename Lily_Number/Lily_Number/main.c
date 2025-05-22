#include <stdio.h>

int main(void)
{
    int i = 0, j = 0;
    for(i = 10000; i <= 99999; i++)
    {
        int sum = 0;
        for(j = 10; j <= 10000; j *= 10)
        {
            sum += (i/j) * (i%j);
        }
        if(sum == i) printf("%d ", i);
    }
    return 0;
}
