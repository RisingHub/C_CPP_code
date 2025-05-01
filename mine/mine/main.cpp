#include "game.h"

void menu()
{
    printf("**************************\n");
    printf("****   1.Start Game   ****\n");
    printf("****   0.Ending    *******\n");
    printf("**************************\n");
}

void game()
{
    char mine[ROWS][COLS]={0};
    char show[ROWS][COLS]={0};
    
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    
    //ShowBoard(mine, ROW, COL);
    ShowBoard(show, ROW, COL);
    
    //布置雷
    SetMine(mine, ROW, COL);
    //ShowBoard(mine, ROW, COL);
    //排雷
    FindMine(mine, show, ROW, COL);
}

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do{
        menu();
        printf("Please choose :>");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("Game Over\n");
                break;
            default:
                printf("The input is error.Please re-enter.\n");
                break;
        }
    }while(input);
    
    return 0;
}
   
