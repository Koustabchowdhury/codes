#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    system("cls");
    printf("------------------------------------------------------------------------\n");
    printf("\n\t\tHello!! Welcome To My Game!!\n");
    printf("\n------------------------------------------------------------------------\n");
    printf("\n\t\t\tAbout Game : \n");
    printf("\n--I have Chosen A Number Between 0 to 20. You Have to Guess My Number--\n");
    printf("\n--You will Get Only 5 Tries--\n");
    printf("\n------------------------------------------------------------------------\n");

    time_t t;
playAgain:
    srand((unsigned)time(&t)); //initialise the random Function
    int randNum = rand() % 21;
    int num, i;

    printf("\nGame Starts...\n");
    for (i = 5; i > 0; i--)
    {
        if (i == 5)
            printf("\n------------------------------------------------------------------------\n");
        printf("\nYou Have %d Tr%s Left..\n", i, i == 1 ? "y" : "ies");
        printf("\nEnter Your Guess : ");
        scanf("%d", &num);
        while (num < 0 || num > 20)
        {
            printf("\nINVALID CHOICE!!\n\nCHOOSE BETWEEN 0-20..");
            printf("\n\nEnter Your Guess Again : ");
            scanf("%d", &num);
        }
        if (randNum == num)
        {
            printf("\nCongratulations!! , You Have Guessed It\n");
            printf("\n------------------------------------------------------------------------\n");
            break;
        }
        else
        {
            (num > randNum) ? ((num - randNum >= 7) ? printf("\nSorry , My Number Is Too Less Than That\n") : printf("\nSorry , My Number Is Less Than That\n")) : ((randNum - num >= 7) ? printf("\nSorry , My Number Is Too High Than That\n") : printf("\nSorry , My Number Is High Than That\n"));
        }
        printf("\n------------------------------------------------------------------------\n");
    }
    if (i == 0)
    {
        printf("\n\t\t\tGame Over!!\n");
        printf("\n\t\tIts Okay , My Number Was %d\n", randNum);
        printf("\n------------------------------------------------------------------------\n");
    }
    int choice;
    printf("\n\tIf You Want To Play Again...Please Enter 1 \n\n\t    Otherwise Put Any Number To Exit : ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        goto playAgain;
    }
    return 0;
}
