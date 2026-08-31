#include <stdio.h>

// Function to find floor of square root of n
int squareRoot(int n)
{
    int low = 1;
    int high = n;
    int ans = 0;

    // Binary Search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if mid * mid is less than or equal to n
        if ((long long)mid * mid <= n)
        {
            // mid can be the answer
            ans = mid;

            // Try to find a larger value
            low = mid + 1;
        }
        else
        {
            // mid is too large
            high = mid - 1;
        }
    }

    return ans;
}

int main()
{
    // Input number
    int n = 36;

    // Find square root
    int result = squareRoot(n);

    // Display result
    printf("Floor Square Root of %d = %d\n", n, result);

    return 0;
}