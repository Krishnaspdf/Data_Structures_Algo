#include <stdio.h>

#define MAX 100

int grid[MAX][MAX];
int n, m;

void DFS(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m)
        return;

    if (grid[r][c] == 0)
        return;

    grid[r][c] = 0;

    DFS(r - 1, c); // Up
    DFS(r + 1, c); // Down
    DFS(r, c - 1); // Left
    DFS(r, c + 1); // Right
}

int numEnclaves() {

    // Traverse first and last columns
    for (int i = 0; i < n; i++) {
        DFS(i, 0);
        DFS(i, m - 1);
    }

    // Traverse first and last rows
    for (int j = 0; j < m; j++) {
        DFS(0, j);
        DFS(n - 1, j);
    }

    // Count remaining land cells
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1)
                count++;
        }
    }

    return count;
}

int main() {
    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter binary matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("Number of Enclaves: %d\n", numEnclaves());

    return 0;
}