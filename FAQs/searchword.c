#include <stdio.h>
#include <string.h>

#define N 3
#define M 4

// Search for the word in the grid
int search(char board[N][M], char word[],
           int i, int j, int index)
{
    // Entire word found
    if (word[index] == '\0')
        return 1;

    // Check boundaries and character match
    if (i < 0 || i >= N || j < 0 || j >= M ||
        board[i][j] != word[index])
        return 0;

    // Mark the cell as visited
    char temp = board[i][j];
    board[i][j] = '#';

    // Search in four directions
    int found =
        search(board, word, i + 1, j, index + 1) ||
        search(board, word, i - 1, j, index + 1) ||
        search(board, word, i, j + 1, index + 1) ||
        search(board, word, i, j - 1, index + 1);

    // Restore the original character
    board[i][j] = temp;

    return found;
}

// Check whether the word exists
int exist(char board[N][M], char word[])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (search(board, word, i, j, 0))
                return 1;
        }
    }

    return 0;
}

int main()
{
    char board[N][M] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    char word[] = "ABCCED";

    if (exist(board, word))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}