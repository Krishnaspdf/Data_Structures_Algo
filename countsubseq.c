#include <stdio.h>

int countSubsequences(int nums[], int n, int index, int sum, int k)
{
    // If all elements are processed
    if (index == n)
    {
        // Count only non-empty subsequences
        if (sum == k)
            return 1;

        return 0;
    }

    // Include current element
    int include = countSubsequences(
        nums, n, index + 1, sum + nums[index], k
    );

    // Exclude current element
    int exclude = countSubsequences(
        nums, n, index + 1, sum, k
    );

    return include + exclude;
}

int main()
{
    int nums[] = {4, 9, 2, 5, 1};
    int n = 5;
    int k = 10;

    int result = countSubsequences(nums, n, 0, 0, k);

    printf("Number of subsequences: %d\n", result);

    return 0;
}
