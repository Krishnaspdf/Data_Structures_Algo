#include <stdio.h>

int longestSubarray(int arr[], int n, int k) {
    int left = 0;
    int sum = 0;
    int maxLen = 0;

    for (int right = 0; right < n; right++) {
        sum += arr[right];

        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum == k) {
            int len = right - left + 1;
            if (len > maxLen)
                maxLen = len;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {1, 2, 1, 1, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;

    printf("%d\n", longestSubarray(arr, n, k));

    return 0;
}