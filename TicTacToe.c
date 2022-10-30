#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
char tic[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice, player;
int checkForWin();
void displayBoard();
void markBoard(char mark);

int main()
{
    int gameStatus = 1;
    char mark;
start:
    player = 1;
    do
    {
        displayBoard();
        player = (player % 2) ? 1 : 2;

        printf("\nPlayer %d , Enter a Number : ", player);
        scanf("%d", &choice);
        mark = (player == 1) ? 'X' : 'O';
        markBoard(mark);
        gameStatus = checkForWin();
        player++;
    } while (gameStatus == -1);
    if (gameStatus == 1)
    {
        printf("\n---------------------------------------------\n");
        printf("\n\t\tPlayer %d WINS!!", --player);
        printf("\n\n\t\t--  GAME OVER --\n");
        printf("\n---------------------------------------------\n");
    }
    else if (gameStatus == 0)
    {
        printf("\n---------------------------------------------\n");
        printf("\n\tIT'S A TIE");
        printf("\n\n\t--  GAME OVER --\n");
        printf("\n---------------------------------------------\n");
    }
    int playAgain;
    printf("\n\tIf You Want To Play Again Press 1\n\n\t\tOr Put Any Number : ");
    scanf("%d", &playAgain);
    if (playAgain == 1)
    {
        for (int i = 1; i < 10; i++)
        {
            if (tic[i] == 'X' || tic[i] == 'O')
            {
                if (i == 1)
                    tic[1] = '1';
                else if (i == 2)
                    tic[2] = '2';
                else if (i == 3)
                    tic[3] = '3';
                else if (i == 4)
                    tic[4] = '4';
                else if (i == 5)
                    tic[5] = '5';
                else if (i == 6)
                    tic[6] = '6';
                else if (i == 7)
                    tic[7] = '7';
                else if (i == 8)
                    tic[8] = '8';
                else if (i == 9)
                    tic[9] = '9';
            }
        }
        goto start;
    }
    else
        return 0;
    return 0;
}

/************************************************************
Function To Return GameStatus
  1 : For Game Is Over With Result(means someone has won)
 -1 : For Game Is in Progress
  0 : For Game Is Over With No Result(means a tie or Draw).
  *************************************************************/
int checkForWin()
{
    int returnValue = 0;
    if (tic[1] == tic[2] && tic[2] == tic[3])
    {
        returnValue = 1;
    }
    else if (tic[4] == tic[5] && tic[5] == tic[6])
    {
        returnValue = 1;
    }
    else if (tic[7] == tic[8] && tic[8] == tic[9])
    {
        returnValue = 1;
    }
    else if (tic[1] == tic[4] && tic[4] == tic[7])
    {
        returnValue = 1;
    }

    else if (tic[2] == tic[5] && tic[5] == tic[8])
    {
        returnValue = 1;
    }
    else if (tic[3] == tic[6] && tic[6] == tic[9])
    {
        returnValue = 1;
    }
    else if (tic[1] == tic[5] && tic[5] == tic[9])
    {
        returnValue = 1;
    }
    else if (tic[3] == tic[5] && tic[5] == tic[7])
    {
        returnValue = 1;
    }
    else if (tic[1] != '1' && tic[2] != '2' && tic[3] != '3' && tic[4] != '4' && tic[5] != '5' && tic[6] != '6' && tic[7] != '7' && tic[8] != '8' && tic[9] != '9')
    {
        returnValue = 0;
    }
    else
    {
        returnValue = -1;
    }
    return returnValue;
}
/* FUNCTION TO DRAW BOARD OF TIC TAC TOE GAME WITH PLAYERS MARK. */
void displayBoard()
{
    system("cls");
    printf("\n\t\tTic Tac Toe\n");
    printf("--------------------------------------------\n");
    printf("\n\tPlayer 1 (X) - Player 2 (O)\n\n\n");
    // printf("   |   |   \n");
    for (int i = 1; i < 10; i++)
    {
        if (i % 3 == 0)
        {
            printf(" %c ", tic[i]);
            if (i < 9)
                printf("\n--- --- ---\n");
        }
        else
            printf(" %c |", tic[i]);
    }
    printf("\n");
}
/***************************************************************
Set The Board with the Correct Character , X or O in the correct spot in the array
*************************************************************/
void markBoard(char mark)
{
    if (choice == 1 && tic[1] == '1')
        tic[1] = mark;
    else if (choice == 2 && tic[2] == '2')
        tic[2] = mark;
    else if (choice == 3 && tic[3] == '3')
        tic[3] = mark;
    else if (choice == 4 && tic[4] == '4')
        tic[4] = mark;
    else if (choice == 5 && tic[5] == '5')
        tic[5] = mark;
    else if (choice == 6 && tic[6] == '6')
        tic[6] = mark;
    else if (choice == 7 && tic[7] == '7')
        tic[7] = mark;
    else if (choice == 8 && tic[8] == '8')
        tic[8] = mark;
    else if (choice == 9 && tic[9] == '9')
        tic[9] = mark;
    else
    {
        printf("INVALID MOVE...\n");
        player--;
        getch(); // Holds/Pauses the printf statement,forces to enter an enter.
    }
}
