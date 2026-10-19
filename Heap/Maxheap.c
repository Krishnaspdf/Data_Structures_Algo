#include <stdio.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Initialize the heap
void initializeHeap() {
    size = 0;
}

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert an element into the max heap
void insert(int x) {
    if (size == MAX)
        return;

    int i = size;
    heap[size++] = x;

    // Move upward to maintain max-heap property
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Return the maximum element
int getMax() {
    if (size == 0)
        return -1;

    return heap[0];
}

// Restore the max heap downward
void heapify(int i) {
    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        // Strict comparison preserves the left-child choice when equal
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }
}

// Remove the maximum element
void extractMax() {
    if (size == 0)
        return;

    heap[0] = heap[size - 1];
    size--;

    if (size > 0)
        heapify(0);
}

// Return the current heap size
int heapSize() {
    return size;
}

// Check whether the heap is empty
int isEmpty() {
    return size == 0;
}

// Change the value at a given 0-based index
void changeKey(int ind, int val) {
    if (ind < 0 || ind >= size)
        return;

    int old = heap[ind];
    heap[ind] = val;

    if (val > old) {
        // Move upward
        while (ind > 0 &&
               heap[(ind - 1) / 2] < heap[ind]) {
            swap(&heap[ind], &heap[(ind - 1) / 2]);
            ind = (ind - 1) / 2;
        }
    } else if (val < old) {
        // Move downward
        heapify(ind);
    }
}

int main() {
    initializeHeap();

    insert(10);
    insert(20);
    insert(15);
    insert(30);
    insert(40);

    printf("Maximum: %d\n", getMax());
    printf("Heap size: %d\n", heapSize());

    extractMax();
    printf("Maximum after extraction: %d\n", getMax());

    changeKey(1, 50);
    printf("Maximum after changeKey: %d\n", getMax());

    printf("Is heap empty? %s\n",
           isEmpty() ? "Yes" : "No");

    return 0;
}