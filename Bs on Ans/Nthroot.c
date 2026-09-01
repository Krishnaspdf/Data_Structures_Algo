#include <stdio.h>

// Function to calculate base^power
// Stops early if the result becomes greater than M
long long power(int base, int exponent, long long M)
{
    long long result = 1;

    for (int i = 0; i < exponent; i++)
    {
        result *= base;

        // If result becomes greater than M,
        // no need to continue calculating
        if (result > M)
        {
            return result;
        }
    }

    return result;
}

// Function to find the Nth root of M
int nthRoot(int N, long long M)
{
    // Handle special case
    if (M == 0)
    {
        return 0;
    }

    // For positive M, root must lie between 1 and M
    long long low = 1;
    long long high = M;

    // Binary Search
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        // Calculate mid^N
        long long value = power(mid, N, M);

        if (value == M)
        {
            // Exact Nth root found
            return (int)mid;
        }
        else if (value < M)
        {
            // mid^N is smaller than M,
            // so search in the right half
            low = mid + 1;
        }
        else
        {
            // mid^N is greater than M,
            // so search in the left half
            high = mid - 1;
        }
    }

    // No integer Nth root exists
    return -1;
}

int main()
{
    // Given values
    int N = 3;
    long long M = 27;

    // Find Nth root
    int result = nthRoot(N, M);

    // Display result
    printf("%dth root of %lld = %d\n", N, M, result);

    return 0;
}