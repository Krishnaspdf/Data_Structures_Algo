#include <stdio.h>
#include <stdlib.h>

#define SIZE 100003

// Node for HashMap
typedef struct Node {
    int sum;
    int index;
    struct Node *next;
} Node;

Node *hashTable[SIZE];

// Hash function
int hash(int key) {
    if (key < 0)
        key = -key;
    return key % SIZE;
}

// Search prefix sum in HashMap
Node* search(int sum) {
    int h = hash(sum);
    Node *temp = hashTable[h];

    while (temp != NULL) {
        if (temp->sum == sum)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Insert prefix sum into HashMap
void insert(int sum, int index) {
    int h = hash(sum);

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

// Function to find longest subarray with sum 0
int longestZeroSumSubarray(int arr[], int n) {
    int sum = 0;
    int maxLen = 0;

    // Initialize hash table
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum becomes 0
        if (sum == 0) {
            maxLen = i + 1;
        }

        Node *found = search(sum);

        if (found != NULL) {
            int len = i - found->index;
            if (len > maxLen)
                maxLen = len;
        } else {
            insert(sum, i);
        }
    }

    return maxLen;
}

// Driver Code
int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest zero sum subarray = %d\n",
           longestZeroSumSubarray(arr, n));

    return 0;
}
