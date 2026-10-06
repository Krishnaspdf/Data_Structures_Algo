#include <stdio.h>

// Sort the array
void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int candidates[100];
int n, target;
int combination[100];
int size = 0;

// Generate unique combinations
void findCombinations(int start, int remaining)
{
    if (remaining == 0)
    {
        printf("[ ");

        for (int i = 0; i < size; i++)
            printf("%d ", combination[i]);

        printf("]\n");
        return;
    }

    for (int i = start; i < n; i++)
    {
        // Skip duplicate elements at the same level
        if (i > start && candidates[i] == candidates[i - 1])
            continue;

        // Since array is sorted, no further element can work
        if (candidates[i] > remaining)
            break;

        // Choose current element
        combination[size++] = candidates[i];

        // Move to i + 1 because each number can be used once
        findCombinations(i + 1, remaining - candidates[i]);

        // Backtrack
        size--;
    }
}

int main()
{
    int input[] = {10, 1, 2, 7, 6, 1, 5};

    n = 7;
    target = 8;

    // Copy input
    for (int i = 0; i < n; i++)
        candidates[i] = input[i];

    // Sort for ordered output and duplicate handling
    sort(candidates, n);

    printf("Unique combinations:\n");

    findCombinations(0, target);

    return 0;
}