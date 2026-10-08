#include <stdio.h>

// Sort the array
void sort(int nums[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

// Print current subset
void printSubset(int subset[], int size)
{
    printf("[ ");

    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);

    printf("]\n");
}

// Generate unique subsets
void generateSubsets(int nums[], int n, int index,
                     int subset[], int size)
{
    // Print current subset
    printSubset(subset, size);

    for (int i = index; i < n; i++)
    {
        // Skip duplicate elements at the same level
        if (i > index && nums[i] == nums[i - 1])
            continue;

        // Include current element
        subset[size] = nums[i];

        generateSubsets(nums, n, i + 1, subset, size + 1);
    }
}

int main()
{
    int nums[] = {1, 2, 2};
    int n = 3;
    int subset[100];

    // Sort first
    sort(nums, n);

    printf("Unique subsets:\n");

    generateSubsets(nums, n, 0, subset, 0);

    return 0;
}