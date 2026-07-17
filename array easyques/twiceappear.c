/*#include <stdio.h>

int singleNumber(int arr[], int n) {
    int freq[1000] = {0};   // Assuming elements are in the range 0-999

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Find the element that appears once
    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 1) {
            return arr[i];
        }
    }

    return -1;
}

int main() {
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Single Number = %d\n", singleNumber(arr, n));

    return 0;
} uding hashing*/

#include <stdio.h>

int singleNumber(int arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main()
{
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Single Number = %d\n", singleNumber(arr, n));

    return 0;
}