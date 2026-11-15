#include <stdio.h>
#include <string.h>

#define MAX 100

int grid[MAX][MAX], visited[MAX][MAX];
int shape[MAX * MAX][2];
int count;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int r, int c, int br, int bc, int n, int m) {
    visited[r][c] = 1;

    shape[count][0] = r - br;
    shape[count][1] = c - bc;
    count++;

    for (int k = 0; k < 4; k++) {
        int nr = r + dx[k];
        int nc = c + dy[k];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            grid[nr][nc] == 1 && !visited[nr][nc]) {
            dfs(nr, nc, br, bc, n, m);
        }
    }
}

int sameShape(int a[][2], int b[][2], int len) {
    for (int i = 0; i < len; i++) {
        if (a[i][0] != b[i][0] || a[i][1] != b[i][1])
            return 0;
    }
    return 1;
}

int main() {
    int n, m, distinct = 0;
    int shapes[MAX * MAX][MAX * MAX][2];
    int sizes[MAX * MAX];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &grid[i][j]);

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                count = 0;
                dfs(i, j, i, j, n, m);

                int unique = 1;

                for (int k = 0; k < distinct; k++) {
                    if (sizes[k] == count &&
                        sameShape(shapes[k], shape, count)) {
                        unique = 0;
                        break;
                    }
                }

                if (unique) {
                    sizes[distinct] = count;
                    for (int k = 0; k < count; k++) {
                        shapes[distinct][k][0] = shape[k][0];
                        shapes[distinct][k][1] = shape[k][1];
                    }
                    distinct++;
                }
            }
        }
    }

    printf("Distinct islands = %d\n", distinct);

    return 0;
}