#include <stdio.h>

// Check whether a subsequence with sum k exists
int subsetSum(int nums[], int n, int index, int sum, int k)
{
    // If required sum is found
    if (sum == k)
        return 1;

    // If all elements are processed
    if (index == n)
        return 0;

    // Include current element
    if (subsetSum(nums, n, index + 1,
                  sum + nums[index], k))
        return 1;

    // Exclude current element
    if (subsetSum(nums, n, index + 1,
                  sum, k))
        return 1;

    return 0;
}

int main()
{
    int nums[] = {1, 2, 3, 4};
    int n = 4;
    int k = 7;

    if (subsetSum(nums, n, 0, 0, k))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}