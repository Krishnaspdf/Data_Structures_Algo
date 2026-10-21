#include <stdio.h>

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

void convertToMaxHeap(int nums[], int n) {
    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }
}

int main() {
    int nums[] = {1, 3, 5, 7, 9, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    convertToMaxHeap(nums, n);

    printf("Max-Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}