#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
void gameInstructions(char []);
void printMatrix(int [4][4]);
void swapNums(int *, int *);
int winSituation(int [4][4]);
void regame(char []);
void gameImplementation(char []);
void store1To15RandomlyInMatrix(int [4][4]);
void printPossibleChoices();
void moveleftInstruction();
void moverightInstruction();
void moveupInstruction();
void movedownInstruction();
void exitInstruction();
void selectChoiceInstruction();
void rightMove(int [4][4], int *, int *, int *);
void leftMove(int [4][4], int *, int *, int *);
void downMove(int [4][4], int *, int *, int *);
void upMove(int [4][4], int *, int *, int *);
void exitGame();

void rightMove(int matrix[4][4], int *blankColi, int *blankRowi, int *remainingMoves)
{
    swapNums(&matrix[(*blankRowi)][(*blankColi)], &matrix[(*blankRowi)][(*blankColi) - 1]);
    *remainingMoves = (*remainingMoves) - 1;
    *blankColi = (*blankColi) - 1; 
}

void leftMove(int matrix[4][4], int *blankColi, int *blankRowi, int *remainingMoves)
{
    swapNums(&matrix[(*blankRowi)][(*blankColi)], &matrix[(*blankRowi)][(*blankColi) + 1]);
    *remainingMoves = (*remainingMoves) - 1;
    *blankColi = (*blankColi) + 1;
}

void downMove(int matrix[4][4], int *blankColi, int *blankRowi, int *remainingMoves)
{
    swapNums(&matrix[(*blankRowi)][(*blankColi)], &matrix[(*blankRowi) - 1][(*blankColi)]);
    *remainingMoves = (*remainingMoves) - 1;
    *blankRowi = (*blankRowi) - 1;
}

void upMove(int matrix[4][4], int *blankColi, int *blankRowi, int *remainingMoves)
{
    swapNums(&matrix[(*blankRowi)][(*blankColi)], &matrix[(*blankRowi) + 1][(*blankColi)]);
    *remainingMoves = (*remainingMoves) - 1;
    *blankRowi = (*blankRowi) + 1;
}

void exitGame()
{
    exit(0);
}

void printPossibleChoices()
{
    printf("\nPossible Choices:\n"); 
}

void moveRightInstruction()
{
    printf("\tPress r to move Right\n");
}

void moveLeftInstruction()
{
    printf("\tPress l to move Left\n");
}

void moveDownInstruction()
{
    printf("\tPress d to move Down\n");
}

void moveUpInstruction()
{
    printf("\tPress u to move Up\n");
}

void exitInstruction()
{
    printf("\tPress e to Exit\n");
}

void selectChoiceInstruction()
{
    printf("Select your choice....");
}

void gameInstructions(char name[])
{
    system("cls");
    printf("Hello %s,\nWelcome to the Number Shifting Game!!!\nLets See What is this game all about along with its rules:\n", name);
    printf("\n\t\tNumber Shifting Game:\n");
    printf("You are given a 4x4 matrix with random values filled.\nExample of One Such Matrix:\n\n");
    
    printf("---------------------------------\n");
    printf("| 10\t| 7\t| 5\t| 3 \t|\n");
    printf("| 6\t| 15\t| 11\t| 4 \t|\n");
    printf("| 9\t| 1\t| 13\t| 8 \t|\n");
    printf("| 12\t| 14\t| 2\t|   \t|\n");
    printf("---------------------------------\n");
    
    printf("\nYou have to convert this random matrix to matrix which looks like this:\n");
    
    printf("---------------------------------\n");
    printf("| 1\t| 2\t| 3\t| 4 \t|\n");
    printf("| 5\t| 6\t| 7\t| 8 \t|\n");
    printf("| 9\t| 10\t| 11\t| 12 \t|\n");
    printf("| 13\t| 14\t| 15\t|   \t|\n");
    printf("---------------------------------\n");
    
    printf("\nGame Rules :\n");
    printf("\t1. You can move only 1 step at a time by pressing keys mentioned below:\n");
    printf("\t\tMove Up  :  By pressing 'u'\n");
    printf("\t\tMove Down  :  By pressing 'd'\n");
    printf("\t\tMove Left  :  By pressing 'l'\n");
    printf("\t\tMove Right  :  By pressing 'r'\n");
    printf("\t2. You can move numbers at an empty position only.\n");
    printf("\t3. For each valid move : your total number of moves will decrease by 1.\n");

    printf("\t4. Winning Situation :\n");
    printf("\t\t1. Number in a 4*4 matrix should be in order from 1 to 15\n");
    printf("\t\t\t1\t2\t3\t4\n");
    printf("\t\t\t5\t6\t7\t8\n");
    printf("\t\t\t9\t10\t11\t12\n");
    printf("\t\t\t13\t14\t15\t\n");

    printf("\t5. You can exit the game at any time by pressing 'e'.\n\n");

    printf("So try to win in minimum number of moves. \n\n");
    printf("\t Happy gaming, Good Luck!\n\n");
    printf("Enter any key to start........ ");
    getch();
}

void printMatrix(int matrix[4][4])
{
    int i, j;
    printf("---------------------------------\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(matrix[i][j])
                printf("| %d", matrix[i][j]);
            else
                printf("|  ");
            printf("\t");
        }
        printf("|\n");
    }
    printf("---------------------------------\n");
}

int winSituation(int matrix[4][4])
{
    int winMatrix[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}}, i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(matrix[i][j] != winMatrix[i][j])
                return 0;
        }
    }
    return 1;
}

void regame(char name[])
{
    char response;
    printf("\n\n\nPress 'y' to play again OR press any key to exit......");
    response = getch();
    switch (response)
    {
        case 'y':
            gameImplementation(name);
            break;
        default:
            exitGame();
    }
}


void store1To15RandomlyInMatrix(int matrix[4][4])
{
    int i, j, k = 0, temp;
    int randomValues[15];

    srand(time(NULL));

    for(i = 0; i < 15; i++)     
         randomValues[i] = i + 1;

    for(i = 0; i < 15;i++)     
    {
         j = i + rand()/(RAND_MAX/(15-i) + 1);
                  
         temp=randomValues[j];
         randomValues[j] = randomValues[i];
         randomValues[i] = temp;
    }

    for(i = 0; i < 4; i++) 
    {
        for(j = 0; j < 4; j++)
        {
            if(i == 3 && j == 3)
                matrix[i][j] = 0;
            else
            {
                matrix[i][j] = randomValues[k];
                k++;
            }
        }
    }
}

void gameImplementation(char name[])
{
    int matrix[4][4];
    store1To15RandomlyInMatrix(matrix);
    int blankRowi = 3, blankColi = 3, remainingMoves = 400, movement;

    while(remainingMoves)
    {
        system("cls");
        printf("Hello %s, ", name);
        printf("Number of Moves left : %d\n\n", remainingMoves);
        printMatrix(matrix);
        
        if (blankRowi == 3 && blankColi == 3)
        {
            printPossibleChoices();
            moveRightInstruction();
            moveDownInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'r':
                    rightMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'd':
                    downMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else if(blankRowi == 3 && blankColi == 0)
        {
            printPossibleChoices();
            moveLeftInstruction();
            moveDownInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'l':
                    leftMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'd':
                    downMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else if(blankRowi == 0 && blankColi == 3)
        {
            printPossibleChoices();
            moveRightInstruction();
            moveUpInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'r':
                    rightMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'u':
                    upMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else if(blankRowi == 0 && blankColi == 0)
        {
            printPossibleChoices();
            moveLeftInstruction();
            moveUpInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'l':
                    leftMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'u':
                    upMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else if(blankRowi == 0)
        {
            printPossibleChoices();
            moveLeftInstruction();
            moveUpInstruction();
            moveRightInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'l':
                    leftMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'u':
                    upMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'r':
                    rightMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else if(blankColi == 0)
        {
            printPossibleChoices();
            moveLeftInstruction();
            moveUpInstruction();
            moveDownInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'l':
                    leftMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'u':
                    upMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'd':
                    downMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else if(blankRowi == 3)
        {
            printPossibleChoices();
            moveLeftInstruction();
            moveDownInstruction();
            moveRightInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'l':
                    leftMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'd':
                    downMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'r':
                    rightMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else if(blankColi == 3)
        {
            printPossibleChoices();
            moveRightInstruction();
            moveUpInstruction();
            moveDownInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'r':
                    rightMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'u':
                    upMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'd':
                    downMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        else
        {
            printPossibleChoices();
            moveRightInstruction();
            moveUpInstruction();
            moveDownInstruction();
            moveLeftInstruction();
            exitInstruction();
            selectChoiceInstruction();
            movement = getch();
            switch(movement)
            {
                case 'r':
                    rightMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'u':
                    upMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'd':
                    downMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'l':
                    leftMove(matrix, &blankColi, &blankRowi, &remainingMoves);
                    break;
                case 'e':
                    exitGame();
                default:
                    printf("");
            }
        }
        if(winSituation(matrix))
        {
            system("cls");
            printf("\nNumber of moves left: %d\n\n", remainingMoves);
            printMatrix(matrix);
            printf("\n\nCongratulations %s, You Won!!!\n", name);
            printf("Great! You are genius in matrix sorting. Keep it up.");
            break;
        }
    }
    if(!winSituation(matrix))
    {
        system("cls");
        printf("\nNumber of moves left: %d\n\n", remainingMoves);
        printMatrix(matrix);
        printf("\n\nYou Lose!!!\n");
        printf("You used all the moves but failed to sort the matrix. Better luck next time!.\n");
    }
    regame(name);
}

void swapNums(int *num1, int *num2)
{
    *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

int main()
{
    char name[50];
    printf("Hello, Welcome to the Number Shifting Game.\nEnter your name: ");
    fgets(name, 45, stdin);
    name[strlen(name) - 1] = '\0';
    gameInstructions(name);
    gameImplementation(name);
    return 0;
}
