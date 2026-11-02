#include <stdio.h>

#define MAX 100000

typedef struct {
    int data[MAX];
    int size;
} Heap;

// Initialize heap
void initHeap(Heap *h) {
    h->size = 0;
}

// Swap elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into max heap
void insertMax(Heap *h, int value) {
    int i = h->size++;
    h->data[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->data[parent] >= h->data[i])
            break;

        swap(&h->data[parent], &h->data[i]);
        i = parent;
    }
}

// Insert into min heap
void insertMin(Heap *h, int value) {
    int i = h->size++;
    h->data[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->data[parent] <= h->data[i])
            break;

        swap(&h->data[parent], &h->data[i]);
        i = parent;
    }
}

// Extract maximum
int extractMax(Heap *h) {
    int result = h->data[0];
    h->data[0] = h->data[--h->size];

    int i = 0;

    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->size &&
            h->data[left] > h->data[largest])
            largest = left;

        if (right < h->size &&
            h->data[right] > h->data[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&h->data[i], &h->data[largest]);
        i = largest;
    }

    return result;
}

// Extract minimum
int extractMin(Heap *h) {
    int result = h->data[0];
    h->data[0] = h->data[--h->size];

    int i = 0;

    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < h->size &&
            h->data[left] < h->data[smallest])
            smallest = left;

        if (right < h->size &&
            h->data[right] < h->data[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }

    return result;
}

// Get maximum
int getMax(Heap *h) {
    return h->data[0];
}

// Get minimum
int getMin(Heap *h) {
    return h->data[0];
}

// MedianFinder structure
typedef struct {
    Heap lowerHalf;
    Heap upperHalf;
} MedianFinder;

// Initialize MedianFinder
void MedianFinderInit(MedianFinder *mf) {
    initHeap(&mf->lowerHalf);
    initHeap(&mf->upperHalf);
}

// Add number
void addNum(MedianFinder *mf, int num) {

    if (mf->lowerHalf.size == 0 ||
        num <= getMax(&mf->lowerHalf)) {

        insertMax(&mf->lowerHalf, num);

    } else {

        insertMin(&mf->upperHalf, num);
    }

    // Balance heaps
    if (mf->lowerHalf.size >
        mf->upperHalf.size + 1) {

        int value = extractMax(&mf->lowerHalf);
        insertMin(&mf->upperHalf, value);

    } else if (mf->lowerHalf.size <
               mf->upperHalf.size) {

        int value = extractMin(&mf->upperHalf);
        insertMax(&mf->lowerHalf, value);
    }
}

// Find median
double findMedian(MedianFinder *mf) {

    if (mf->lowerHalf.size ==
        mf->upperHalf.size) {

        return ((double)getMax(&mf->lowerHalf) +
                getMin(&mf->upperHalf)) / 2.0;
    }

    return getMax(&mf->lowerHalf);
}

// Main function
int main() {

    MedianFinder mf;

    MedianFinderInit(&mf);

    addNum(&mf, 1);
    addNum(&mf, 2);

    printf("Median: %.5f\n", findMedian(&mf));

    addNum(&mf, 3);

    printf("Median: %.5f\n", findMedian(&mf));

    return 0;
}