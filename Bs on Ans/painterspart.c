#include <stdio.h>

// Greedily counts how many painters are needed if no painter 
// works for more than 'maxTime' units of time.
static int countPaintersNeeded(const int *boards, int N, long long maxTime) {
    int painters = 1;
    long long currentTime = 0;

    for (int i = 0; i < N; i++) {
        if (currentTime + boards[i] > maxTime) {
            painters++;
            currentTime = boards[i];
        } else {
            currentTime += boards[i];
        }
    }
    return painters;
}

long long findMinimumTime(const int *boards, int N, int K) {
    if (N == 0) return 0;

    long long low = 0;
    long long high = 0;

    for (int i = 0; i < N; i++) {
        if (boards[i] > low) {
            low = boards[i]; // Largest board length
        }
        high += boards[i];   // Sum of all board lengths
    }

    long long result = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Check if 'mid' maximum time is achievable with K or fewer painters
        if (countPaintersNeeded(boards, N, mid) <= K) {
            result = mid;
            high = mid - 1; // Try to minimize the max time further
        } else {
            low = mid + 1;  // 'mid' is too small; increase max allowed time
        }
    }

    return result;
}

int main() {
    int boards[] = {10, 20, 30, 40};
    int N = sizeof(boards) / sizeof(boards[0]);
    int K = 2;

    long long minTime = findMinimumTime(boards, N, K);
    printf("Minimum time required to paint all boards: %lld units\n", minTime);

    return 0;
}
