#include <stdio.h>

void heapify(int nums[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] < nums[smallest])
        smallest = left;

    if (right < n && nums[right] < nums[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = nums[i];
        nums[i] = nums[smallest];
        nums[smallest] = temp;

        heapify(nums, n, smallest);
    }
}

void buildMinHeap(int nums[], int n) {
    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }
}

int main() {
    int nums[] = {9, 4, 7, 1, 3, 6, 2};
    int n = sizeof(nums) / sizeof(nums[0]);

    buildMinHeap(nums, n);

    printf("Min-Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}