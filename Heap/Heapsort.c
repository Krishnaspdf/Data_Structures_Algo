#include <stdio.h>

// Restore the max-heap property
void heapify(int nums[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[largest])
        largest = left;

    if (right < n && nums[right] > nums[largest])
        largest = right;

    if (largest != i) {
        int temp = nums[i];
        nums[i] = nums[largest];
        nums[largest] = temp;

        heapify(nums, n, largest);
    }
}

// Sort the array using Heap Sort
void heapSort(int nums[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(nums, n, i);

    // Move the maximum element to the end
    for (int i = n - 1; i > 0; i--) {
        int temp = nums[0];
        nums[0] = nums[i];
        nums[i] = temp;

        heapify(nums, i, 0);
    }
}

int main() {
    int nums[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    heapSort(nums, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}