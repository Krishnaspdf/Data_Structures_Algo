#include <stdio.h>

#define MAX 100

typedef struct {
    int r, c;
} Cell;

int orangesRotting(int grid[MAX][MAX], int n, int m) {
    Cell queue[MAX * MAX];
    int front = 0, rear = 0;
    int fresh = 0, minutes = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    // Add rotten oranges and count fresh oranges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2)
                queue[rear++] = (Cell){i, j};
            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    // BFS
    while (front < rear && fresh > 0) {
        int size = rear - front;

        for (int i = 0; i < size; i++) {
            Cell curr = queue[front++];

            for (int d = 0; d < 4; d++) {
                int r = curr.r + dr[d];
                int c = curr.c + dc[d];

                if (r >= 0 && c >= 0 &&
                    r < n && c < m &&
                    grid[r][c] == 1) {

                    grid[r][c] = 2;
                    fresh--;

                    queue[rear++] = (Cell){r, c};
                }
            }
        }

        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    int n, m;
    int grid[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter grid:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &grid[i][j]);

    printf("Minimum Minutes: %d\n",
           orangesRotting(grid, n, m));

    return 0;
}