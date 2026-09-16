#include <stdio.h>

// Find the row containing maximum element in a column
int maxInColumn(int mat[][100], int n, int col)
{
    int maxRow = 0;

    for (int i = 1; i < n; i++)
    {
        if (mat[i][col] > mat[maxRow][col])
            maxRow = i;
    }

    return maxRow;
}

// Find any peak element
void findPeak(int mat[][100], int n, int m, int *peakRow, int *peakCol)
{
    int low = 0;
    int high = m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Find maximum element in middle column
        int row = maxInColumn(mat, n, mid);

        int left = (mid == 0) ? -1 : mat[row][mid - 1];
        int right = (mid == m - 1) ? -1 : mat[row][mid + 1];

        // Check if current element is a peak
        if (mat[row][mid] > left && mat[row][mid] > right)
        {
            *peakRow = row;
            *peakCol = mid;
            return;
        }

        // Move towards the larger neighbour
        if (left > mat[row][mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    *peakRow = -1;
    *peakCol = -1;
}

int main()
{
    int mat[100][100] = {
        {10, 8, 10, 10},
        {14, 13, 12, 11},
        {15, 9, 11, 21},
        {16, 17, 19, 20}
    };

    int n = 4, m = 4;
    int row, col;

    findPeak(mat, n, m, &row, &col);

    printf("Peak element index: [%d, %d]\n", row, col);

    return 0;
}