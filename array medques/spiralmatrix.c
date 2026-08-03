#include <stdio.h>

// Function to print the matrix in spiral order
void spiralTraversal(int matrix[][4], int rows, int cols)
{
    // Initialize the boundaries
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    printf("Spiral Order: ");

    // Continue until all elements are traversed
    while (top <= bottom && left <= right)
    {
        // Traverse from left to right
        for (int i = left; i <= right; i++)
        {
            printf("%d ", matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; i++)
        {
            printf("%d ", matrix[i][right]);
        }
        right--;

        // Traverse from right to left
        // Only if rows remain
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top
        // Only if columns remain
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }

    printf("\n");
}

int main()
{
    // Input matrix
    int matrix[4][4] =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int rows = 4;
    int cols = 4;

    // Call the function
    spiralTraversal(matrix, rows, cols);

    return 0;
}
