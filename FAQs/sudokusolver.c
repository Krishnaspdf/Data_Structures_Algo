#include <stdio.h>

#define N 9

// Check whether placing num is valid
int isSafe(char board[N][N], int row, int col, char num) {
    for (int i = 0; i < N; i++) {
        // Check row and column
        if (board[row][i] == num || board[i][col] == num)
            return 0;

        // Check 3x3 sub-box
        int r = 3 * (row / 3) + i / 3;
        int c = 3 * (col / 3) + i % 3;

        if (board[r][c] == num)
            return 0;
    }
    return 1;
}

// Solve Sudoku using backtracking
int solveSudoku(char board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku(board))
                            return 1;

                        // Backtrack
                        board[row][col] = '.';
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

// Print the Sudoku board
void printBoard(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
}

int main() {
    char board[N][N] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (solveSudoku(board)) {
        printf("Solved Sudoku:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}