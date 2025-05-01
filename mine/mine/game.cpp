#include "game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}

void ShowBoard(char board[ROWS][COLS],int row,int col)
{
    printf("-------------MINE CLEARANCE--------------------\n");
    for(int i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    
    for(int i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for(int j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
    int cnt = EASY_COUNT;
    while(cnt)
    {
        int x = rand()%9 + 1;
        int y = rand()%9 + 1;
        
        if(mine[x][y] == '0')
        {
            mine[x][y] = '1';
            cnt--;
        }
    }
}

static int GetMineCount(char mine[ROWS][COLS],int x,int y)
{
    int cnt = 0;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            cnt += (mine[x+i][y+j] -'0');
        }
    }
    return cnt;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    //循环 非法输入
    while(win < row*col-EASY_COUNT)
    {
        printf("Please enter the coordinates you want to troubleshoot :>");
        scanf("%d%d", &x, &y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            int cnt = GetMineCount(mine, x, y);
            if(mine[x][y] == '1')
            {
                printf("Regretly, mine exploded.Game over!\n");
                ShowBoard(mine, row, col);
                break;
            }
            else
            {
                show[x][y] = cnt + '0';
                ShowBoard(show, row, col);
                win++;
            }
        }
        else
        {
            printf("The coordinates are ERROR.Please re-enter.\n");
        }
    }
    if(win == row*col-EASY_COUNT)
    {
        printf("*************************\n");
        printf("Congratulations!You win!.\n");
        printf("*************************\n");
        ShowBoard(mine, row, col);
    }
}

