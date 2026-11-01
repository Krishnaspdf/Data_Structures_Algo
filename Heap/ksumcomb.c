#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int sum;
    int i;
    int j;
} Node;

Node heap[MAX];
int heapSize = 0;

int visited[MAX][2];

// Swap two nodes
void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into max heap
void insert(Node node) {
    int i = heapSize++;
    heap[i] = node;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].sum >= heap[i].sum)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

// Extract maximum
Node extractMax() {
    Node result = heap[0];
    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize &&
            heap[left].sum > heap[largest].sum)
            largest = left;

        if (right < heapSize &&
            heap[right].sum > heap[largest].sum)
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    return result;
}

// Descending sort
int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    return (x < y) - (x > y);
}

void maxKSumCombinations(
    int nums1[], int nums2[],
    int n, int m, int k
) {
    qsort(nums1, n, sizeof(int), compare);
    qsort(nums2, m, sizeof(int), compare);

    if (k > n * m)
        k = n * m;

    heapSize = 0;

    insert((Node){nums1[0] + nums2[0], 0, 0});

    printf("Maximum K combinations:\n");

    for (int count = 0; count < k; count++) {

        Node current = extractMax();

        printf("%d ", current.sum);

        int i = current.i;
        int j = current.j;

        if (i + 1 < n) {
            insert((Node){
                nums1[i + 1] + nums2[j],
                i + 1, j
            });
        }

        if (j + 1 < m) {
            insert((Node){
                nums1[i] + nums2[j + 1],
                i, j + 1
            });
        }
    }
}

int main() {
    int nums1[] = {3, 2, 4, 1};
    int nums2[] = {6, 5, 3, 2};

    int n = 4, m = 4;
    int k = 3;

    maxKSumCombinations(nums1, nums2, n, m, k);

    return 0;
}