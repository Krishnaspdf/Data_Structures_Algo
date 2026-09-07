#include <stdio.h>

/**
 * Finds the k-th positive integer missing from a strictly increasing array.
 * 
 * @param vec Pointer to the array of integers
 * @param n Size of the array
 * @param k The position of the missing integer
 * @return The k-th missing positive integer
 */
int findKthPositive(int vec[], int n, int k) {
    int low = 0, high = n - 1;
    
    // Apply Binary Search to find the boundary where the number of missing elements is >= k
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Number of missing integers up to index mid
        int missing = vec[mid] - (mid + 1);
        
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    // The k-th missing number is given by low + k (or high + 1 + k)
    return low + k;
}

int main() {
    int vec[] = {2, 3, 4, 7, 11};
    int n = sizeof(vec) / sizeof(vec[0]);
    int k = 5;

    int result = findKthPositive(vec, n, k);
    printf("The %d-th missing positive integer is: %d\n", k, result);

    return 0;
}
