#include <stdio.h>

#define MAX 100

int image[MAX][MAX];
int rows, cols;
int oldColor, newColor;

void DFS(int r, int c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols)
        return;

    if (image[r][c] != oldColor)
        return;

    image[r][c] = newColor;

    DFS(r - 1, c); // Up
    DFS(r + 1, c); // Down
    DFS(r, c - 1); // Left
    DFS(r, c + 1); // Right
}

void floodFill(int sr, int sc, int color) {
    oldColor = image[sr][sc];
    newColor = color;

    if (oldColor == newColor)
        return;

    DFS(sr, sc);
}

int main() {
    int sr, sc, color;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter image:\n");

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &image[i][j]);

    printf("Enter starting row and column: ");
    scanf("%d %d", &sr, &sc);

    printf("Enter new color: ");
    scanf("%d", &color);

    floodFill(sr, sc, color);

    printf("Modified Image:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", image[i][j]);

        printf("\n");
    }

    return 0;
}