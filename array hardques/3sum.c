#include <stdio.h>
#include <stdlib.h>

// Function used by qsort() to sort the array
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to find unique triplets whose sum is zero
void threeSum(int arr[], int n)
{
    // Sort the array first
    qsort(arr, n, sizeof(int), compare);

    printf("Triplets with sum zero:\n");

    // Fix the first element of the triplet
    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        // Two pointers
        int left = i + 1;
        int right = n - 1;

        // Find the remaining two elements
        while (left < right)
        {
            int sum = arr[i] + arr[left] + arr[right];

            // If sum is zero, a valid triplet is found
            if (sum == 0)
            {
                printf("[%d, %d, %d]\n",
                       arr[i], arr[left], arr[right]);

                // Skip duplicate second elements
                while (left < right && arr[left] == arr[left + 1])
                {
                    left++;
                }

                // Skip duplicate third elements
                while (left < right && arr[right] == arr[right - 1])
                {
                    right--;
                }

                // Move both pointers
                left++;
                right--;
            }

            // If sum is smaller than zero,
            // increase left to get a larger value
            else if (sum < 0)
            {
                left++;
            }

            // If sum is greater than zero,
            // decrease right to get a smaller value
            else
            {
                right--;
            }
        }
    }
}

int main()
{
    // Input array
    int arr[] = {-1, 0, 1, 2, -1, -4};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find triplets whose sum is zero
    threeSum(arr, n);

    return 0;
}v
