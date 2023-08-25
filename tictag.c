#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to print the game board
void print_board(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
}

// Function to check if a player has won
bool has_won(char player, char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char players[2] = {'X', 'O'};
    int current_player = rand() % 2; // Randomly choose starting player

    while (true) {
        system("clear"); // Clear the console (Linux/macOS)
        //system("cls"); // Clear the console (Windows)
        print_board(board);
        printf("Player %c's turn. Enter row (0-2) and column (0-2): ", players[current_player]);

        int row, col;
        scanf("%d %d", &row, &col);

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = players[current_player];
            
            if (has_won(players[current_player], board)) {
                system("clear"); // Clear the console (Linux/macOS)
                //system("cls"); // Clear the console (Windows)
                print_board(board);
                printf("Player %c wins!\n", players[current_player]);
                break;
            }
            
            bool is_draw = true;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (board[i][j] == ' ') {
                        is_draw = false;
                        break;
                    }
                }
            }
            if (is_draw) {
                system("clear"); // Clear the console (Linux/macOS)
                //system("cls"); // Clear the console (Windows)
                print_board(board);
                printf("The game is a draw!\n");
                break;
            }
            
            current_player = 1 - current_player; // Switch players
        }
    }

    return 0;
}
