#include <stdio.h>

// Find maximum pile size
int findMax(int a[], int n)
{
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

// Calculate total hours required at speed k
long long hoursRequired(int a[], int n, int k)
{
    long long hours = 0;

    for (int i = 0; i < n; i++)
    {
        // Ceiling division
        hours += (a[i] + k - 1) / k;
    }

    return hours;
}

// Find minimum eating speed
int minEatingSpeed(int a[], int n, int h)
{
    int low = 1;
    int high = findMax(a, n);
    int ans = high;

    // Binary search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (hoursRequired(a, n, mid) <= h)
        {
            // Speed is sufficient, try smaller speed
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // Speed is too slow
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int a[] = {7, 15, 6, 3};
    int n = 4;
    int h = 8;

    int result = minEatingSpeed(a, n, h);

    printf("Minimum eating speed: %d\n", result);

    return 0;
}