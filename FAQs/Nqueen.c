#include <stdio.h>
#include <stdlib.h>

int board[20][20];
int n;

// Check whether a queen can be placed safely
int isSafe(int row, int col)
{
    int i, j;

    // Check the same column
    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return 0;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return 0;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return 0;

    return 1;
}

// Print the current solution
void printBoard()
{
    printf("[\n");

    for (int i = 0; i < n; i++)
    {
        printf("  \"");

        for (int j = 0; j < n; j++)
            printf("%c", board[i][j] ? 'Q' : '.');

        printf("\"");

        if (i < n - 1)
            printf(",");

        printf("\n");
    }

    printf("]\n\n");
}

// Solve N-Queens using backtracking
void solveNQueens(int row)
{
    // All queens have been placed
    if (row == n)
    {
        printBoard();
        return;
    }

    // Try placing a queen in each column
    for (int col = 0; col < n; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;

            solveNQueens(row + 1);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main()
{
    n = 4;

    // Initialize the board
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    printf("Solutions for N = %d:\n", n);

    solveNQueens(0);

    return 0;
}