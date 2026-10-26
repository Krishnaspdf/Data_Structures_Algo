#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

#define MAX_K 1000

// Create a new linked-list node
ListNode* createNode(int val) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Swap two node pointers
void swap(ListNode **a, ListNode **b) {
    ListNode *temp = *a;
    *a = *b;
    *b = temp;
}

// Restore the min-heap property
void heapify(ListNode *heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left]->val < heap[smallest]->val)
        smallest = left;

    if (right < n && heap[right]->val < heap[smallest]->val)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(heap, n, smallest);
    }
}

// Insert a node into the min-heap
void insert(ListNode *heap[], int *size, ListNode *node) {
    int i = (*size)++;
    heap[i] = node;

    while (i > 0 && heap[i]->val < heap[(i - 1) / 2]->val) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Remove and return the minimum node
ListNode* extractMin(ListNode *heap[], int *size) {
    ListNode *minNode = heap[0];

    heap[0] = heap[--(*size)];

    if (*size > 0)
        heapify(heap, *size, 0);

    return minNode;
}

// Merge k sorted linked lists
ListNode* mergeKLists(ListNode *heads[], int k) {
    ListNode *heap[MAX_K];
    int size = 0;

    // Add the first node of each non-empty list
    for (int i = 0; i < k; i++) {
        if (heads[i] != NULL)
            insert(heap, &size, heads[i]);
    }

    ListNode dummy;
    dummy.next = NULL;
    ListNode *tail = &dummy;

    while (size > 0) {
        // Extract the smallest node
        ListNode *node = extractMin(heap, &size);

        // Append it to the result
        tail->next = node;
        tail = node;

        // Insert the next node from the same list
        if (node->next != NULL)
            insert(heap, &size, node->next);
    }

    tail->next = NULL;
    return dummy.next;
}

// Print the linked list
void printList(ListNode *head) {
    while (head != NULL) {
        printf("%d", head->val);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }
    printf("\n");
}

// Build a linked list from an array
ListNode* createList(int arr[], int n) {
    ListNode dummy;
    dummy.next = NULL;
    ListNode *tail = &dummy;

    for (int i = 0; i < n; i++) {
        tail->next = createNode(arr[i]);
        tail = tail->next;
    }

    return dummy.next;
}

int main() {
    int a[] = {1, 2, 3, 4};
    int b[] = {-4, -3};
    int c[] = {-5, -3, 1, 2, 3, 4};

    ListNode *heads[3];

    heads[0] = createList(a, 4);
    heads[1] = createList(b, 2);
    heads[2] = createList(c, 6);

    ListNode *result = mergeKLists(heads, 3);

    printf("Merged list:\n");
    printList(result);

    return 0;
}
