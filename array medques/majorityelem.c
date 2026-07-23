#include <stdio.h>

// Function to find the majority element
int majorityElement(int nums[], int n)
{
    // Variable to store the current candidate
    int candidate = 0;

    // Variable to maintain the vote count
    int count = 0;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // If count becomes 0, choose the current element as candidate
        if (count == 0)
        {
            candidate = nums[i];
        }

        // If current element is the candidate, increase count
        if (nums[i] == candidate)
        {
            count++;
        }
        // Otherwise, decrease count
        else
        {
            count--;
        }
    }

    // Since the problem guarantees a majority element,
    // the candidate is the majority element.
    return candidate;
}

int main()
{
    // Input array
    int nums[] = {2, 2, 1, 1, 1, 2, 2};

    // Calculate the size of the array
    int n = sizeof(nums) / sizeof(nums[0]);

    // Find the majority element
    int result = majorityElement(nums, n);

    // Display the result
    printf("Majority Element: %d\n", result);

    return 0;
}