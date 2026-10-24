#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain the min-heap property
void heapify(int heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;

    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Insert an element into the min-heap
void insert(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove and return the minimum element
int extractMin(int heap[], int *size) {
    int min = heap[0];
    heap[0] = heap[--(*size)];

    if (*size > 0)
        heapify(heap, *size, 0);

    return min;
}

// Sort the k-sorted array
void sortKSortedArray(int arr[], int n, int k) {
    int capacity = (k + 1 < n) ? k + 1 : n;
    int heap[capacity];
    int size = 0;
    int index = 0;

    // Insert the first k+1 elements
    for (int i = 0; i < capacity; i++)
        insert(heap, &size, arr[i]);

    // Extract minimum and insert remaining elements
    for (int i = capacity; i < n; i++) {
        arr[index++] = extractMin(heap, &size);
        insert(heap, &size, arr[i]);
    }

    // Extract remaining elements
    while (size > 0)
        arr[index++] = extractMin(heap, &size);
}

int main() {
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    sortKSortedArray(arr, n, k);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}
