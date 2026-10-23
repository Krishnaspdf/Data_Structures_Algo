#include <stdio.h>

void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        heapify(heap, n, smallest);
    }
}

int findKthLargest(int nums[], int n, int k) {
    int heap[k];

    // Insert the first k elements into the heap
    for (int i = 0; i < k; i++)
        heap[i] = nums[i];

    // Build a min-heap
    for (int i = k / 2 - 1; i >= 0; i--)
        heapify(heap, k, i);

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        if (nums[i] > heap[0]) {
            heap[0] = nums[i];
            heapify(heap, k, 0);
        }
    }

    // Root contains the kth largest element
    return heap[0];
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 2;

    printf("%d\n", findKthLargest(nums, n, k));

    return 0;
}
