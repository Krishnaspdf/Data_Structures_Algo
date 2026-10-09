#include <stdio.h>

// Store the current combination
int combination[9];

// Generate valid combinations
void findCombinations(int start, int k, int n, int index)
{
    // Combination contains k numbers
    if (k == 0)
    {
        if (n == 0)
        {
            printf("[ ");
            for (int i = 0; i < index; i++)
                printf("%d ", combination[i]);
            printf("]\n");
        }
        return;
    }

    // Try numbers from start to 9
    for (int i = start; i <= 9; i++)
    {
        if (i > n)
            break;

        combination[index] = i;

        findCombinations(i + 1, k - 1, n - i, index + 1);
    }
}

int main()
{
    int k = 3;
    int n = 7;

    printf("Valid combinations:\n");
    findCombinations(1, k, n, 0);

    return 0;
}