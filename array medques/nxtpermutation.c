#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse the array from index start to end
void reverse(int nums[], int start, int end)
{
    while (start < end)
    {
        swap(&nums[start], &nums[end]);
        start++;
        end--;
    }
}

// Function to generate the next permutation
void nextPermutation(int nums[], int n)
{
    // Step 1: Find the first index from the end
    // where nums[i] < nums[i + 1]
    int index = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }

    // If no such index exists,
    // the array is the last permutation
    if (index == -1)
    {
        reverse(nums, 0, n - 1);
        return;
    }

    // Step 2: Find the first element greater than nums[index]
    // starting from the end
    for (int i = n - 1; i > index; i--)
    {
        if (nums[i] > nums[index])
        {
            swap(&nums[i], &nums[index]);
            break;
        }
    }

    // Step 3: Reverse the remaining part
    reverse(nums, index + 1, n - 1);
}

int main()
{
    // Input array
    int nums[] = {1, 2, 3};

    // Calculate size
    int n = sizeof(nums) / sizeof(nums[0]);

    // Find next permutation
    nextPermutation(nums, n);

    // Display the result
    printf("Next Permutation: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    return 0;
}
