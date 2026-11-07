#include <stdio.h>

#define MAX 100

int n, m;
char grid[MAX][MAX];
int visited[MAX][MAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void DFS(int r, int c) {
    visited[r][c] = 1;

    for (int i = 0; i < 8; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];

        if (nr >= 0 && nr < n &&
            nc >= 0 && nc < m &&
            grid[nr][nc] == '1' &&
            !visited[nr][nc]) {

            DFS(nr, nc);
        }
    }
}

int countIslands() {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '1' && !visited[i][j]) {
                count++;
                DFS(i, j);
            }
        }
    }

    return count;
}

int main() {
    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter grid:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }

    printf("Number of Islands: %d\n", countIslands());

    return 0;
}
