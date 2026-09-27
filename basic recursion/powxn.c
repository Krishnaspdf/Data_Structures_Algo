#include <stdio.h>

// Calculate x raised to n using binary exponentiation
double power(double x, int n)
{
    long long N = n;

    // Handle negative exponent
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;

    while (N > 0)
    {
        // If exponent is odd
        if (N % 2 == 1)
            result *= x;

        // Square the base
        x *= x;

        // Divide exponent by 2
        N /= 2;
    }

    return result;
}

int main()
{
    double x = 2.0000;
    int n = 10;

    printf("%.6f\n", power(x, n));

    return 0;
}