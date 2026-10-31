#include <stdio.h>

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintain min-heap property
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

// Insert an element into min-heap
void insert(int heap[], int *size, int val) {
    int i = (*size)++;
    heap[i] = val;

    while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract minimum element
int extractMin(int heap[], int *size) {
    int min = heap[0];

    heap[0] = heap[--(*size)];

    if (*size > 0)
        heapify(heap, *size, 0);

    return min;
}

// Calculate minimum connection cost
long long connectSticks(int sticks[], int n) {
    if (n <= 1)
        return 0;

    int heap[n];
    int size = 0;

    // Insert all sticks into min-heap
    for (int i = 0; i < n; i++)
        insert(heap, &size, sticks[i]);

    long long totalCost = 0;

    // Connect the two smallest sticks repeatedly
    while (size > 1) {
        int first = extractMin(heap, &size);
        int second = extractMin(heap, &size);

        int combined = first + second;

        totalCost += combined;

        insert(heap, &size, combined);
    }

    return totalCost;
}

int main() {
    int sticks[] = {2, 4, 3};
    int n = sizeof(sticks) / sizeof(sticks[0]);

    printf("Minimum connection cost: %lld\n",
           connectSticks(sticks, n));

    return 0;
}
