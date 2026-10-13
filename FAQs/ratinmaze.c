#include <stdio.h>

#define N 4

int grid[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 1}
};

int visited[N][N];
char path[100];

// Explore all possible paths
void findPaths(int row, int col, int index)
{
    // Destination reached
    if (row == N - 1 && col == N - 1)
    {
        path[index] = '\0';
        printf("%s\n", path);
        return;
    }

    // Mark current cell as visited
    visited[row][col] = 1;

    // Move Down
    if (row + 1 < N && grid[row + 1][col] == 1 &&
        !visited[row + 1][col])
    {
        path[index] = 'D';
        findPaths(row + 1, col, index + 1);
    }

    // Move Left
    if (col - 1 >= 0 && grid[row][col - 1] == 1 &&
        !visited[row][col - 1])
    {
        path[index] = 'L';
        findPaths(row, col - 1, index + 1);
    }

    // Move Right
    if (col + 1 < N && grid[row][col + 1] == 1 &&
        !visited[row][col + 1])
    {
        path[index] = 'R';
        findPaths(row, col + 1, index + 1);
    }

    // Move Up
    if (row - 1 >= 0 && grid[row - 1][col] == 1 &&
        !visited[row - 1][col])
    {
        path[index] = 'U';
        findPaths(row - 1, col, index + 1);
    }

    // Backtrack: unmark current cell
    visited[row][col] = 0;
}

int main()
{
    // No path if the starting or destination cell is blocked
    if (grid[0][0] == 0 || grid[N - 1][N - 1] == 0)
    {
        printf("No path exists.\n");
        return 0;
    }

    printf("Possible paths:\n");
    findPaths(0, 0, 0);

    return 0;
}