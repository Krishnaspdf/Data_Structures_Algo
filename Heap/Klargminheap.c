#include <stdio.h>

#define MAX 10000

typedef struct {
    int heap[MAX];
    int size;
    int k;
} KthLargest;

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Restore min-heap property downward
void heapifyDown(KthLargest *obj, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < obj->size &&
        obj->heap[left] < obj->heap[smallest])
        smallest = left;

    if (right < obj->size &&
        obj->heap[right] < obj->heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&obj->heap[i], &obj->heap[smallest]);
        heapifyDown(obj, smallest);
    }
}

// Insert into min-heap
void insert(KthLargest *obj, int val) {
    int i = obj->size;
    obj->heap[obj->size++] = val;

    while (i > 0 &&
           obj->heap[i] < obj->heap[(i - 1) / 2]) {
        swap(&obj->heap[i], &obj->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Initialize KthLargest
void KthLargestInit(KthLargest *obj, int k, int nums[], int n) {
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < n; i++)
        KthLargestAdd(obj, nums[i]);
}

// Add a number and return kth largest
int KthLargestAdd(KthLargest *obj, int val) {
    if (obj->size < obj->k) {
        insert(obj, val);
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

int main() {
    KthLargest obj;

    int nums[] = {4, 5, 8, 2};
    int k = 3;
    int n = sizeof(nums) / sizeof(nums[0]);

    KthLargestInit(&obj, k, nums, n);

    printf("%d\n", KthLargestAdd(&obj, 3));
    printf("%d\n", KthLargestAdd(&obj, 5));
    printf("%d\n", KthLargestAdd(&obj, 10));
    printf("%d\n", KthLargestAdd(&obj, 9));
    printf("%d\n", KthLargestAdd(&obj, 4));

    return 0;
}
