#include <stdio.h>

// Function to display the Tic-Tac-Toe board
void display_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a player has won
int check_winner(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1; // Player wins
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1; // Player wins
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1; // Player wins
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1; // Player wins
    return 0; // No winner yet
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char player = 'X';
    int row, col;

    printf("Welcome to Tic-Tac-Toe!\n");

    for (int turn = 0; turn < 9; turn++) {
        printf("\nPlayer %c's turn:\n", player);
        display_board(board);

        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            turn--; // Repeat the same turn
            continue;
        }

        board[row][col] = player;

        if (check_winner(board, player)) {
            printf("\nPlayer %c wins!\n", player);
            display_board(board);
            break;
        }

        player = (player == 'X') ? 'O' : 'X'; // Switch players
    }

    if (!check_winner(board, 'X') && !check_winner(board, 'O')) {
        printf("\nIt's a draw!\n");
        display_board(board);
    }

    return 0;
}