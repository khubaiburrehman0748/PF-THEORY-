#include <stdio.h>
#include <stdbool.h>

char gameBoard[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

int playerCurrentRow = 4;
int playerCurrentCol = 4;
int playerPreviousRow = 4;
int playerPreviousCol = 4;

void displayGameBoard() {
    for (int row = 0; row < 5; row++) {
        printf("{");
        for (int col = 0; col < 5; col++) {
            if (col != 4) {
                printf("%c|", gameBoard[row][col]);
            } else {
                printf("%c", gameBoard[row][col]);
            }
        }
        printf("}\n");
    }
}

bool isMoveValid(char direction) {
    int targetRow = playerCurrentRow;
    int targetCol = playerCurrentCol;

    if (direction == 'w' || direction == 'W') {
        targetRow = playerCurrentRow - 1;
    } else if (direction == 'a' || direction == 'A') {
        targetCol = playerCurrentCol - 1;
    } else if (direction == 's' || direction == 'S') {
        targetRow = playerCurrentRow + 1;
    } else if (direction == 'd' || direction == 'D') {
        targetCol = playerCurrentCol + 1;
    }

    if (targetRow > 4 || targetCol > 4 || targetRow < 0 || targetCol < 0) {
        return false;
    } else if (gameBoard[targetRow][targetCol] == 'X') {
        return false;
    } else {
        playerPreviousRow = playerCurrentRow;
        playerPreviousCol = playerCurrentCol;
        playerCurrentRow = targetRow;
        playerCurrentCol = targetCol;
        return true;
    }
}

void updateGameBoard() {
    gameBoard[playerCurrentRow][playerCurrentCol] = 'P';
    gameBoard[playerPreviousRow][playerPreviousCol] = ' ';
}

int main() {
    char moveDirection = ' ';

    while (moveDirection != 'q' && moveDirection != 'Q') {
        displayGameBoard();
        printf("Enter a move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &moveDirection);

        if (isMoveValid(moveDirection)) {
            updateGameBoard();
        }
    }

    return 0;
}
