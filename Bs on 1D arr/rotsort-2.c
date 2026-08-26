#include <stdio.h>
#include <stdbool.h>

bool search(int arr[], int n, int k) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Target found
        if (arr[mid] == k) {
            return true;
        }

        // Edge Case: Elements at low, mid, and high are all equal.
        // We cannot determine the sorted half, so we shrink the search space.
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // Check if the target lies within the sorted left half
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1; // Target is in the left half
            } else {
                low = mid + 1;  // Target is in the right half
            }
        } 
        // Otherwise, the right half must be sorted
        else {
            // Check if the target lies within the sorted right half
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;  // Target is in the right half
            } else {
                high = mid - 1; // Target is in the left half
            }
        }
    }

    return false; // Target not found
}

// Driver code to test the function
int main() {
    int arr[] = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    if (search(arr, n, k)) {
        printf("Result: True\n");
    } else {
        printf("Result: False\n");
    }

    return 0;
}
