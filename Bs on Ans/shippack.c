#include <stdio.h>
#include <limits.h>

/**
 * Checks if it is possible to ship all packages within 'd' days 
 * given a specific ship capacity.
 * 
 * @param weights Pointer to the array of package weights
 * @param n Size of the weights array
 * @param d Maximum number of days allowed
 * @param capacity The current ship capacity being tested
 * @return 1 if possible, 0 otherwise
 */
int canShipInDays(int weights[], int n, int d, int capacity) {
    int days = 1;
    int currentWeight = 0;
    
    for (int i = 0; i < n; i++) {
        if (currentWeight + weights[i] > capacity) {
            days++;
            currentWeight = weights[i];
        } else {
            currentWeight += weights[i];
        }
    }
    
    return days <= d;
}

/**
 * Finds the least-weight capacity of a ship to ship all packages within 'd' days.
 * 
 * @param weights Pointer to the array of package weights
 * @param n Size of the weights array
 * @param d Maximum number of days allowed
 * @return The minimum ship capacity
 */
int shipWithinDays(int weights[], int n, int d) {
    int low = INT_MIN;
    int high = 0;
    
    // Determine the search range:
    // low = maximum element in weights (ship must carry at least the heaviest package)
    // high = sum of all weights (ship carries everything in 1 day)
    for (int i = 0; i < n; i++) {
        if (weights[i] > low) {
            low = weights[i];
        }
        high += weights[i];
    }
    
    int ans = high;

    // Apply Binary Search on the range of possible capacities
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canShipInDays(weights, n, d, mid)) {
            ans = mid;       // Record valid capacity
            high = mid - 1;  // Try to find a smaller capacity on the left
        } else {
            low = mid + 1;   // Capacity is too small, we need a larger one
        }
    }

    return ans;
}

int main() {
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(weights) / sizeof(weights[0]);
    int d = 5;

    int result = shipWithinDays(weights, n, d);
    printf("The least weight capacity is: %d\n", result);

    return 0;
}
