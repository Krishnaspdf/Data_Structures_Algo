#include <stdio.h>

// Function to set the matrix zeroes
void setZeroes(int matrix[][3], int rows, int cols)
{
    // Arrays to mark which rows and columns
    // should be set to zero
    int row[rows];
    int col[cols];

    // Initialize marker arrays with 0
    for (int i = 0; i < rows; i++)
    {
        row[i] = 0;
    }

    for (int j = 0; j < cols; j++)
    {
        col[j] = 0;
    }

    // Traverse the matrix
    // If a cell contains 0, mark its row and column
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Set the marked rows and columns to 0
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    // Input matrix
    int matrix[3][3] =
    {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    int rows = 3;
    int cols = 3;

    // Call the function
    setZeroes(matrix, rows, cols);

    // Display the updated matrix
    printf("Updated Matrix:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
