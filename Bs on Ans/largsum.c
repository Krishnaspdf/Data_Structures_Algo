#include <stdio.h>

// Helper function to count how many contiguous subarrays are needed 
// if the maximum allowed sum for any subarray is 'maxSum'
static int countSubarrays(const int *A, int N, long long maxSum) {
    int partitions = 1;
    long long currentSum = 0;

    for (int i = 0; i < N; i++) {
        if (currentSum + A[i] > maxSum) {
            partitions++;
            currentSum = A[i];
        } else {
            currentSum += A[i];
        }
    }
    return partitions;
}

long long splitArray(const int *A, int N, int K) {
    if (K > N || N == 0) return -1; // Invalid configuration

    long long low = 0;
    long long high = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > low) {
            low = A[i]; // Max single element
        }
        high += A[i];   // Sum of all elements
    }

    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // If 'mid' maximum sum requires K or fewer subarrays, it's valid
        if (countSubarrays(A, N, mid) <= K) {
            ans = mid;
            high = mid - 1; // Try to find a smaller maximum sum
        } else {
            low = mid + 1;  // 'mid' is too small; increase the sum bound
        }
    }

    return ans;
}

int main() {
    int A[] = {7, 2, 5, 10, 8};
    int N = sizeof(A) / sizeof(A[0]);
    int K = 2;

    long long result = splitArray(A, N, K);
    printf("Minimized largest sum: %lld\n", result);

    return 0;
}
