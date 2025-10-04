#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int checkWinner(int field[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (field[i][0] != 0 && field[i][0] == field[i][1] && field[i][1] == field[i][2])
        {
            return field[i][0];
        }

        if (field[0][i] != 0 && field[0][i] == field[1][i] && field[1][i] == field[2][i])
        {
            return field[0][i];
        }
    }

    if (field[0][0] != 0 && field[0][0] == field[1][1] && field[1][1] == field[2][2])
    {
        return field[0][0];
    }

    if (field[0][2] != 0 && field[0][2] == field[1][1] && field[1][1] == field[2][0])
    {
        return field[0][2];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (field[i][j] == 0)
            {
                return 0;
            }
        }
    }

    return -1;
}

void printField(int field[3][3])
{
    printf("\n+---+---+---+\n");

    for (int i = 0; i < 3; i++)
    {
        printf("|");

        for (int j = 0; j < 3; j++)
        {
            switch (field[i][j])
            {
            case 0:
                printf("   ");
                break;

            case 1:
                printf("\033[0;31m X ");
                break;

            case 2:
                printf("\033[0;34m O ");
                break;
            }

            printf("\033[0m|");
        }

        printf("\n+---+---+---+\n");
    }

    return;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    printf("\033[2J\033[H");

    printf("--- Tic Tac Toe ---\n\n");
    printf("Singleplayer | Two Player [0|1]: ");

    int mode;
    scanf("%d", &mode);

    int currentPlayer = 2;
    int field[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};

    if (mode == 0)
    {
        while (checkWinner(field) == 0)
        {
            printf("\033[2J\033[H");
            currentPlayer = currentPlayer == 1 ? 2 : 1;
            printField(field);

            if (currentPlayer == 1)
            {
                bool inputValid = false;
                int x = 0;
                int y = 0;

                printf("\n--- Player ---\n");

                while (!inputValid)
                {
                    printf("\nEnter x position: ");
                    scanf("%d", &x);
                    printf("\nEnter y position: ");
                    scanf("%d", &y);

                    if (field[y][x] == 0)
                    {
                        inputValid = true;
                        field[y][x] = currentPlayer;
                    }
                    else
                    {
                        printf("\nPosition invalid. Try again.\n");
                    }
                }
            }
            else
            {
                bool inputValid = false;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (field[i][j] == 0)
                        {
                            field[i][j] = 2;
                            if (checkWinner(field) == 2)
                            {
                                inputValid = true;
                                break;
                            }
                            field[i][j] = 0;
                        }
                    }
                    if (inputValid)
                        break;
                }

                if (!inputValid)
                {
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (field[i][j] == 0)
                            {
                                field[i][j] = 1;
                                if (checkWinner(field) == 1)
                                {
                                    field[i][j] = 2;
                                    inputValid = true;
                                    break;
                                }
                                field[i][j] = 0;
                            }
                        }
                        if (inputValid)
                            break;
                    }
                }

                if (!inputValid && field[1][1] == 0)
                {
                    field[1][1] = 2;
                    inputValid = true;
                }

                int corners[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
                int emptyCorners[4][2];
                int emptyCount = 0;
                
                for (int i = 0; i < 4; i++)
                {
                    int y = corners[i][0], x = corners[i][1];
                    if (field[y][x] == 0)
                    {
                        emptyCorners[emptyCount][0] = y;
                        emptyCorners[emptyCount][1] = x;
                        emptyCount++;
                    }
                }

                if (emptyCount > 0)
                {
                    int pick = rand() % emptyCount;
                    field[emptyCorners[pick][0]][emptyCorners[pick][1]] = 2;
                    inputValid = true;
                }

                while (!inputValid)
                {
                    int x = rand() % 3;
                    int y = rand() % 3;

                    if (field[y][x] == 0)
                    {
                        inputValid = true;
                        field[y][x] = 2;
                    }
                }
            }
        }

        printf("\033[2J\033[H\n");
        printField(field);

        if (checkWinner(field) == -1)
        {
            printf("\nIt's a draw!\n");
        }
        else
        {
            printf("\n%s won!\n", currentPlayer == 1 ? "Player" : "Computer");
        }
    }
    else
    {
        printf("\033[2J\033[H");

        char player1Name[20] = {0};
        char player2Name[20] = {0};

        printf("Player 1 name: ");
        scanf("%s", player1Name);

        printf("Player 2 name: ");
        scanf("%s", player2Name);

        while (checkWinner(field) == 0)
        {
            printf("\033[2J\033[H");
            currentPlayer = currentPlayer == 1 ? 2 : 1;
            printField(field);

            printf("\n--- Player %s ---\n", currentPlayer == 1 ? player1Name : player2Name);

            bool inputValid = false;
            int x = 0;
            int y = 0;

            while (!inputValid)
            {
                printf("\nEnter x position: ");
                scanf("%d", &x);
                printf("\nEnter y position: ");
                scanf("%d", &y);

                if (field[y][x] == 0)
                {
                    inputValid = true;
                    field[y][x] = currentPlayer;
                }
                else
                {
                    printf("\nPosition invalid. Try again.\n");
                }
            }
        }

        printf("\033[2J\033[H\n");
        printField(field);

        if (checkWinner(field) == -1)
        {
            printf("\nIt's a draw!\n");
        }
        else
        {
            printf("\nPlayer %s won!\n", currentPlayer == 1 ? player1Name : player2Name);
        }
    }

    return 0;
}