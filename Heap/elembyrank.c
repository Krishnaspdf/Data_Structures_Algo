#include <stdio.h>
#include <stdlib.h>

// Compare function for sorting
int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

void replaceWithRank(int arr[], int n) {
    int sorted[n];
    int rank[n];

    // Copy the original array
    for (int i = 0; i < n; i++)
        sorted[i] = arr[i];

    // Sort the copy
    qsort(sorted, n, sizeof(int), compare);

    // Assign ranks to unique elements
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || sorted[i] != sorted[i - 1])
            sorted[count++] = sorted[i];
    }

    // Find each element's rank
    for (int i = 0; i < n; i++) {
        int left = 0, right = count - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (sorted[mid] == arr[i]) {
                rank[i] = mid + 1;
                break;
            } else if (sorted[mid] < arr[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    // Replace original elements with their ranks
    for (int i = 0; i < n; i++)
        arr[i] = rank[i];
}

int main() {
    int arr[] = {40, 10, 20, 30, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    replaceWithRank(arr, n);

    printf("Rank array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}