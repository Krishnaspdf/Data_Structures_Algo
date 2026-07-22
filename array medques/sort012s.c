#include <stdio.h>

// Function to sort the array containing only 0s, 1s, and 2s
void sortColors(int nums[], int n)
{
    // Pointer for placing 0s
    int low = 0;

    // Pointer for traversing the array
    int mid = 0;

    // Pointer for placing 2s
    int high = n - 1;

    // Continue until mid crosses high
    while (mid <= high)
    {
        // Case 1: Current element is 0
        if (nums[mid] == 0)
        {
            // Swap nums[low] and nums[mid]
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;

            // Move both pointers forward
            low++;
            mid++;
        }

        // Case 2: Current element is 1
        else if (nums[mid] == 1)
        {
            // 1 is already in its correct region
            mid++;
        }

        // Case 3: Current element is 2
        else
        {
            // Swap nums[mid] with nums[high]
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            // Reduce high pointer
            // Do not increment mid because the swapped element
            // needs to be checked in the next iteration
            high--;
        }
    }
}

int main()
{
    // Input array
    int nums[] = {2, 0, 2, 1, 1, 0};

    // Calculate number of elements
    int n = sizeof(nums) / sizeof(nums[0]);

    // Call sorting function
    sortColors(nums, n);

    // Display the sorted array
    printf("Sorted Array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}