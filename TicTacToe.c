#include <stdio.h>
#include <stdbool.h>
#include <string.h>
    
int checkWinner(int field[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (field[i][0] != 0 && field[i][0] == field[i][1] && field[i][1] == field[i][2]) {
            return field[i][0];
        } 

        if (field[0][i] != 0 && field[0][i] == field[1][i] && field[1][i] == field[2][i]) {
            return field[0][i];
        } 
    }

    if (field[0][0] != 0 && field[0][0] == field[1][1] && field[1][1] == field[2][2]) {
        return field[0][0];
    }

    if (field[0][2] != 0 && field[0][2] == field[1][1] && field[1][1] == field[2][0]) {
        return field[0][2];
    }

    return 0;
}

void printField(int field[3][3]) {
    printf("\n+---+---+---+\n");

    for (int i = 0; i < 3; i++) {
        printf("|");

        for (int j = 0; j < 3; j++) {
            switch (field[i][j]) {
                case 0:
                    printf("   |");
                    break;

                case 1:
                    printf(" X |");
                    break;

                case 2:
                    printf(" O |");
                    break;
            }
        }

        printf("\n+---+---+---+\n");
    }

    return;
}

int main(int argc, char* argv[]) {
    int field[3][3] ={
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int currentPlayer = 2;

    while (checkWinner(field) == 0) {
        printf("\033[2J\033[H");
        currentPlayer = currentPlayer == 1 ? 2 : 1;
        printField(field);
        
        printf("\n--- Player %d ---\n", currentPlayer);

        bool inputValid = false;
        int x = 0;
        int y = 0;

        while (!inputValid)
        {
            printf("\nEnter x position: ");
            scanf("%d", &x);
            printf("\nEnter y position: ");
            scanf("%d", &y);

            if (field[y][x] == 0) {
                inputValid = true;
                field[y][x] = currentPlayer;
            } else {
                printf("\nPosition invalid. Try again.\n");
            }
        }

    }

    printf("\nPlayer %d won!\n", currentPlayer);
}