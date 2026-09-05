#include <stdio.h>
#include <limits.h>

/**
 * Calculates the total sum after dividing each element of the array by the given divisor
 * and rounding up (ceil division) using integer arithmetic.
 * 
 * @param arr Pointer to the array of integers
 * @param n Size of the array
 * @param divisor The current divisor being tested
 * @return The sum of division results
 */
int calculateSum(int arr[], int n, int divisor) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        // Equivalent to ceil(arr[i] / divisor)
        sum += (arr[i] + divisor - 1) / divisor;
    }
    return sum;
}

/**
 * Finds the smallest positive integer divisor such that the sum of the division 
 * results is less than or equal to the given threshold limit.
 * 
 * @param arr Pointer to the array of integers
 * @param n Size of the array
 * @param limit The threshold value
 * @return The smallest valid divisor
 */
int smallestDivisor(int arr[], int n, int limit) {
    // The minimum possible divisor is always 1
    int low = 1;
    // The maximum possible divisor is the maximum element in the array
    int high = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > high) {
            high = arr[i];
        }
    }

    int ans = -1;

    // Apply Binary Search on the range of divisors [1, max(arr)]
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (calculateSum(arr, n, mid) <= limit) {
            ans = mid;       // Record valid divisor
            high = mid - 1;  // Try to find a smaller divisor on the left side
        } else {
            low = mid + 1;   // Sum is too large, we need a larger divisor
        }
    }

    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int limit = 8;

    int result = smallestDivisor(arr, n, limit);
    printf("The smallest divisor is: %d\n", result);

    return 0;
}
