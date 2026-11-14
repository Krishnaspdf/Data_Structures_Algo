#include <stdio.h>

#define MAX 100

void dfs(char mat[MAX][MAX], int n, int m, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m ||
        mat[i][j] != 'O')
        return;

    mat[i][j] = '#';

    dfs(mat, n, m, i - 1, j);
    dfs(mat, n, m, i + 1, j);
    dfs(mat, n, m, i, j - 1);
    dfs(mat, n, m, i, j + 1);
}

void solve(char mat[MAX][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        dfs(mat, n, m, i, 0);
        dfs(mat, n, m, i, m - 1);
    }

    for (int j = 0; j < m; j++) {
        dfs(mat, n, m, 0, j);
        dfs(mat, n, m, n - 1, j);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'O')
                mat[i][j] = 'X';
            else if (mat[i][j] == '#')
                mat[i][j] = 'O';
        }
    }
}

int main() {
    int n, m;
    char mat[MAX][MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &n, &m);

    printf("Enter matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %c", &mat[i][j]);

    solve(mat, n, m);

    printf("Modified matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%c ", mat[i][j]);
        printf("\n");
    }

    return 0;
}