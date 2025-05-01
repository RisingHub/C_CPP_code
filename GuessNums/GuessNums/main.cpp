#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void menu()
{
    printf("***************\n");
    printf("*** 1.play ****\n");
    printf("*** 0.end  ****\n");
    printf("***************\n");
}
void game()
{
    //1-100
    int r=rand()%100+1;
    int guess = 0;
    int count = 5;
    int flag = 0;
    while(count)
    {
        printf("You have %d opportunities.Please input your number -> ",count);
        scanf("%d",&guess);
        if(guess > r)
        {
            printf("It's bigger.\n");
        }
        else if(guess < r)
        {
            printf("It's smaller.\n");
        }
        else
        {
            flag = 1;
            printf("Excellent!You're right!\n");break;
        }
        count--;
    }
    
    if(!flag) printf("You lose!\n");
}

int main()
{
    srand((unsigned int)time(NULL));
    int input = 0;
    do{
            menu();
            printf("Please choose -> ");
            scanf("%d",&input);
            switch(input)
            {
                case 1:
                    game();
                    break;
                case 0:
                    printf("Game over!\n");
                    break;
                default:
                    printf("Please input again!\n");
                    break;
            }
    }while(input);
    return 0;
}
