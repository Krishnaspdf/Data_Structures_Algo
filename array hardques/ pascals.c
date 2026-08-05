#include <stdio.h>

// Function to generate Pascal's Triangle
void pascalTriangle(int n)
{
    // Traverse through each row
    for (int i = 0; i < n; i++)
    {
        int value = 1;

        // Print leading spaces for triangle shape
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print elements in the current row
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", value);

            // Calculate the next value using the formula
            // C(i, j+1) = C(i, j) * (i-j) / (j+1)
            value = value * (i - j) / (j + 1);
        }

        printf("\n");
    }
}

int main()
{
    // Number of rows
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Generate Pascal's Triangle
    pascalTriangle(n);

    return 0;
}