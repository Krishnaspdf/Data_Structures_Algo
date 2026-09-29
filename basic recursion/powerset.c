#include <stdio.h>

int nums[] = {1, 2, 3};
int n = 3;

// Generate all subsets
void generateSubsets(int index, int subset[], int size)
{
    // Print current subset
    printf("[ ");

    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);

    printf("]\n");

    // Try including remaining elements
    for (int i = index; i < n; i++)
    {
        subset[size] = nums[i];

        generateSubsets(i + 1, subset, size + 1);
    }
}

int main()
{
    int subset[100];

    printf("All subsets:\n");

    generateSubsets(0, subset, 0);

    return 0;
}