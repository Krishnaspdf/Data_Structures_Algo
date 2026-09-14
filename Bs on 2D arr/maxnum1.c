#include <stdio.h>

// Find the first occurrence of 1 in a row
int firstOne(int row[], int m)
{
    int low = 0, high = m - 1;
    int ans = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (row[mid] == 1)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

// Find row with maximum number of 1s
int rowWithMax1s(int mat[][100], int n, int m)
{
    int maxOnes = 0;
    int result = -1;

    for (int i = 0; i < n; i++)
    {
        int first = firstOne(mat[i], m);
        int ones = m - first;

        // Update only if strictly more 1s
        // This automatically keeps the smaller index on ties
        if (ones > maxOnes)
        {
            maxOnes = ones;
            result = i;
        }
    }

    return result;
}

int main()
{
    int mat[100][100] = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    int n = 4, m = 4;

    int result = rowWithMax1s(mat, n, m);

    printf("Row with maximum number of 1s: %d\n", result);

    return 0;
}
