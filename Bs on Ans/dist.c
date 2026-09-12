#include <stdio.h>
#include <math.h>

// Calculates the number of new gas stations needed to keep all 
// adjacent distances <= dist
static int requiredStations(double dist, const int *arr, int n) {
    int count = 0;
    
    for (int i = 0; i < n - 1; i++) {
        double gap = arr[i + 1] - arr[i];
        int stationsNeeded = (int)(gap / dist);
        
        // If the gap is an exact multiple of 'dist', the last endpoint 
        // lands on an existing station, so we subtract 1.
        if (fabs(gap - (dist * stationsNeeded)) < 1e-9) {
            stationsNeeded--;
        }
        
        count += stationsNeeded;
    }
    
    return count;
}

double minMaxGasStationDist(const int *arr, int n, int k) {
    double low = 0.0;
    double high = 0.0;

    // Find the maximum gap in the initial array
    for (int i = 0; i < n - 1; i++) {
        double gap = arr[i + 1] - arr[i];
        if (gap > high) {
            high = gap;
        }
    }

    // Binary search with precision threshold (1e-6)
    while (high - low > 1e-6) {
        double mid = low + (high - low) / 2.0;

        if (requiredStations(mid, arr, n) > k) {
            low = mid;  // Need a larger allowed distance
        } else {
            high = mid; // Try to minimize the distance further
        }
    }

    return high;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 9;

    double result = minMaxGasStationDist(arr, n, k);
    printf("Minimized maximum distance: %.6f\n", result);

    return 0;
}
