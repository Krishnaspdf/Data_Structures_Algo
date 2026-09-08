#include <stdio.h>
#include <stdlib.h>

/**
 * Comparator function for qsort to sort the array in ascending order.
 */
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Checks if it is possible to place 'k' cows in the stalls such that 
 * the minimum distance between any two cows is at least 'dist'.
 * 
 * @param arr Pointer to the sorted array of stall positions
 * @param n Size of the array
 * @param k Number of aggressive cows
 * @param dist The minimum distance being tested
 * @return 1 if possible, 0 otherwise
 */
int canPlaceCows(int arr[], int n, int k, int dist) {
    int cowsPlaced = 1;         // Place the first cow in the first stall
    int lastPosition = arr[0];  // Track the position of the last placed cow

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPosition >= dist) {
            cowsPlaced++;
            lastPosition = arr[i];
            if (cowsPlaced == k) {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Finds the maximum possible minimum distance between 'k' aggressive cows.
 * 
 * @param arr Pointer to the array of stall positions
 * @param n Size of the array
 * @param k Number of aggressive cows
 * @return The maximum possible minimum distance
 */
int aggressiveCows(int arr[], int n, int k) {
    // Sort the stall positions to apply greedy placement
    qsort(arr, n, sizeof(int), compare);

    int low = 1; 
    int high = arr[n - 1] - arr[0]; // Maximum possible distance
    int ans = -1;

    // Apply Binary Search on the range of possible distances
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(arr, n, k, mid)) {
            ans = mid;       // This distance is possible, record it
            low = mid + 1;   // Try to find a larger minimum distance
        } else {
            high = mid - 1;  // This distance is too large, try a smaller one
        }
    }

    return ans;
}

int main() {
    int arr[] = {0, 3, 4, 7, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int result = aggressiveCows(arr, n, k);
    printf("The maximum possible minimum distance is: %d\n", result);

    return 0;
}
