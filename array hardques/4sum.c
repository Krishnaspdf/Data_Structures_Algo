#include <stdio.h>
#include <stdlib.h>

// Comparator function used by qsort()
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to find unique quadruplets whose sum is equal to target
void fourSum(int arr[], int n, int target)
{
    // Sort the array first
    qsort(arr, n, sizeof(int), compare);

    printf("Quadruplets with sum %d:\n", target);

    // Fix the first element
    for (int i = 0; i < n - 3; i++)
    {
        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        // Fix the second element
        for (int j = i + 1; j < n - 2; j++)
        {
            // Skip duplicate second elements
            if (j > i + 1 && arr[j] == arr[j - 1])
            {
                continue;
            }

            // Two pointers for the remaining two elements
            int left = j + 1;
            int right = n - 1;

            // Search for the remaining two elements
            while (left < right)
            {
                long long sum = (long long)arr[i]
                              + arr[j]
                              + arr[left]
                              + arr[right];

                // If sum equals target, quadruplet is found
                if (sum == target)
                {
                    printf("[%d, %d, %d, %d]\n",
                           arr[i], arr[j],
                           arr[left], arr[right]);

                    // Skip duplicate third elements
                    while (left < right &&
                           arr[left] == arr[left + 1])
                    {
                        left++;
                    }

                    // Skip duplicate fourth elements
                    while (left < right &&
                           arr[right] == arr[right - 1])
                    {
                        right--;
                    }

                    // Move both pointers
                    left++;
                    right--;
                }

                // If sum is smaller than target,
                // increase left to obtain a larger sum
                else if (sum < target)
                {
                    left++;
                }

                // If sum is greater than target,
                // decrease right to obtain a smaller sum
                else
                {
                    right--;
                }
            }
        }
    }
}

int main()
{
    // Input array
    int arr[] = {1, 0, -1, 0, -2, 2};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target sum
    int target = 0;

    // Find and print the unique quadruplets
    fourSum(arr, n, target);

    return 0;
}
