#include <stdio.h>

// Find the maximum blooming day
int findMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Find the minimum blooming day
int findMin(int arr[], int n)
{
    int min = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

// Check if m bouquets can be made by 'day'
int canMake(int arr[], int n, int m, int k, int day)
{
    int bouquets = 0;
    int consecutive = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            // Rose has bloomed
            consecutive++;

            // k adjacent roses form one bouquet
            if (consecutive == k)
            {
                bouquets++;
                consecutive = 0;
            }
        }
        else
        {
            // Adjacency is broken
            consecutive = 0;
        }
    }

    return bouquets >= m;
}

// Find minimum number of days
int minDays(int arr[], int n, int m, int k)
{
    // Not enough roses
    if ((long long)m * k > n)
        return -1;

    int low = findMin(arr, n);
    int high = findMax(arr, n);
    int ans = -1;

    // Binary search on number of days
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canMake(arr, n, m, k, mid))
        {
            // Possible, try fewer days
            ans = mid;
            high = mid - 1;
        }
        else
        {
            // Not possible, need more days
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    int arr[] = {7, 7, 7, 7, 13, 11, 12, 7};
    int n = 8;
    int m = 2;
    int k = 3;

    int result = minDays(arr, n, m, k);

    printf("Minimum number of days: %d\n", result);

    return 0;
}