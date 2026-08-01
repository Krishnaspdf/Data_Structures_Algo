#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to rotate the matrix by 90 degrees clockwise
void rotateMatrix(int matrix[][3], int n)
{
    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(&matrix[i][j], &matrix[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            swap(&matrix[i][left], &matrix[i][right]);
            left++;
            right--;
        }
    }
}

int main()
{
    // Input matrix
    int matrix[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int n = 3;

    // Rotate the matrix
    rotateMatrix(matrix, n);

    // Display the rotated matrix
    printf("Rotated Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}