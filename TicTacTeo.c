#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';  
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

int checkWinner(char board[SIZE][SIZE]) {
    
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return (board[i][0] == 'X') ? 1 : 2;  
        }
    }

   
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return (board[0][j] == 'X') ? 1 : 2;  
        }
    }

  
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return (board[0][0] == 'X') ? 1 : 2;  
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return (board[0][2] == 'X') ? 1 : 2;  
    }

    return 0;  
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;  
            }
        }
    }
    return 1;  
}

int main() {
    char board[SIZE][SIZE];
    initializeBoard(board);
    int player = 1;  
    int row, col;

    while (1) {
        displayBoard(board);
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d %d", &row, &col);

        
        if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != ' ') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        
        board[row - 1][col - 1] = (player == 1) ? 'X' : 'O';

       
        int winner = checkWinner(board);
        if (winner) {
            displayBoard(board);
            printf("Player %d wins!\n", winner);
            break;
        }

        
        if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

       
        player = (player == 1) ? 2 : 1;
    }

    return 0;
}
