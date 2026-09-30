#include <stdio.h>

#define MOD 1000000007LL

// Calculate (base^exp) % MOD
long long power(long long base, long long exp)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % MOD;

        base = (base * base) % MOD;
        exp /= 2;
    }

    return result;
}

// Count good digit strings
long long countGoodStrings(long long n)
{
    long long evenPositions = (n + 1) / 2;
    long long oddPositions = n / 2;

    long long evenWays = power(5, evenPositions);
    long long oddWays = power(4, oddPositions);

    return (evenWays * oddWays) % MOD;
}

int main()
{
    long long n = 4;

    printf("Number of good digit strings: %lld\n",
           countGoodStrings(n));

    return 0;
}