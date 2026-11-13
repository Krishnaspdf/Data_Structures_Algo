#include <stdio.h>

#define MAX 100

int dist[MAX][MAX];
int queue[MAX * MAX][2];

void nearestOne(int grid[MAX][MAX], int n, int m) {
    int front = 0, rear = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;

            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                queue[rear][0] = i;
                queue[rear++][1] = j;
            }
        }
    }

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front++][1];

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n &&
                ny >= 0 && ny < m &&
                dist[nx][ny] == -1) {

                dist[nx][ny] = dist[x][y] + 1;

                queue[rear][0] = nx;
                queue[rear++][1] = ny;
            }
        }
    }
}

int main() {
    int n, m, grid[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter binary grid:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &grid[i][j]);

    nearestOne(grid, n, m);

    printf("Distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }

    return 0;
}