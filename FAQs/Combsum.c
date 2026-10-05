#include <stdio.h>

int nums[] = {2, 3, 6, 7};
int n = 4;
int target = 7;

int combination[100];
int size = 0;

// Print current combination
void printCombination()
{
    printf("[ ");

    for (int i = 0; i < size; i++)
        printf("%d ", combination[i]);

    printf("]\n");
}

// Generate all combinations
void findCombinations(int index, int remaining)
{
    // Target reached
    if (remaining == 0)
    {
        printCombination();
        return;
    }

    // Try each number
    for (int i = index; i < n; i++)
    {
        // Skip numbers greater than remaining
        if (nums[i] > remaining)
            continue;

        // Choose current number
        combination[size++] = nums[i];

        // Same index because number can be reused
        findCombinations(i, remaining - nums[i]);

        // Backtrack
        size--;
    }
}

int main()
{
    printf("Combinations:\n");

    findCombinations(0, target);

    return 0;
}