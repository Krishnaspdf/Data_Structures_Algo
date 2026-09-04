#include <stdio.h>

// Function to find maximum subarray sum
int maxSubArray(int nums[], int n)
{
    int currentSum = nums[0];
    int maxSum = nums[0];

    // Traverse the array
    for (int i = 1; i < n; i++)
    {
        // Either extend the previous subarray
        // or start a new subarray
        if (currentSum + nums[i] > nums[i])
            currentSum = currentSum + nums[i];
        else
            currentSum = nums[i];

        // Update maximum sum
        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

int main()
{
    int nums[] = {2, 3, 5, -2, 7, -4};
    int n = 6;

    int result = maxSubArray(nums, n);

    printf("Maximum subarray sum: %d\n", result);

    return 0;
}