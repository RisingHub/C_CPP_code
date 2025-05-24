#include <stdio.h>
#include <stdlib.h>
#define COLS 5
#define ROWS 3

int main(void)
{
    int** p = (int**)malloc(sizeof(int*)*ROWS);
    int i = 0, j = 0;
    for(i = 0; i < ROWS; i++)
    {
        p[i]  = (int*)malloc(sizeof(int)*COLS);
    }
    
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            p[i][j] = i*j+1;
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    
    for(i = 0; i < ROWS; i++)
    {
        free(p[i]);
    }
    free(p);
    p = NULL;
    return 0;
}
