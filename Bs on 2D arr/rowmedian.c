#include <stdio.h>

// Find number of elements <= x in a row
int upperBound(int row[], int n, int x)
{
    int low = 0, high = n;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (row[mid] <= x)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

// Count elements <= x in the whole matrix
int countLessEqual(int mat[][100], int m, int n, int x)
{
    int count = 0;

    for (int i = 0; i < m; i++)
        count += upperBound(mat[i], n, x);

    return count;
}

// Find median of the matrix
int findMedian(int mat[][100], int m, int n)
{
    int low = mat[0][0];
    int high = mat[0][n - 1];

    // Find minimum and maximum elements
    for (int i = 1; i < m; i++)
    {
        if (mat[i][0] < low)
            low = mat[i][0];

        if (mat[i][n - 1] > high)
            high = mat[i][n - 1];
    }

    int required = (m * n) / 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int count = countLessEqual(mat, m, n, mid);

        if (count <= required)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

int main()
{
    int mat[100][100] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int m = 3, n = 3;

    printf("Median: %d\n", findMedian(mat, m, n));

    return 0;
}