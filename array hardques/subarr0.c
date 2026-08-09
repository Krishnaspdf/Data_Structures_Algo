#include <stdio.h>
#include <string.h>

#define SIZE 10007

// Structure for storing prefix sum and its first occurrence
typedef struct
{
    int key;       // Prefix sum
    int index;     // First index where prefix sum occurred
    int used;      // Indicates whether this position is occupied
} HashNode;

HashNode hashTable[SIZE];

// Hash function
int hashFunction(int key)
{
    if (key < 0)
        key = -key;

    return key % SIZE;
}

// Insert prefix sum and its first occurrence
void insert(int key, int index)
{
    int position = hashFunction(key);

    // Handle collisions using linear probing
    while (hashTable[position].used &&
           hashTable[position].key != key)
    {
        position = (position + 1) % SIZE;
    }

    // Store only the first occurrence
    // because it gives the longest possible subarray
    if (!hashTable[position].used)
    {
        hashTable[position].used = 1;
        hashTable[position].key = key;
        hashTable[position].index = index;
    }
}

// Search for a prefix sum
int search(int key)
{
    int position = hashFunction(key);

    // Search until an unused position is found
    while (hashTable[position].used)
    {
        if (hashTable[position].key == key)
        {
            return hashTable[position].index;
        }

        position = (position + 1) % SIZE;
    }

    // Prefix sum not found
    return -1;
}

// Function to find the longest zero-sum subarray
int longestZeroSumSubarray(int arr[], int n)
{
    // Initialize hash table
    memset(hashTable, 0, sizeof(hashTable));

    int prefixSum = 0;
    int maxLength = 0;

    // Prefix sum 0 occurs before the array starts
    // at index -1
    insert(0, -1);

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // Calculate prefix sum
        prefixSum += arr[i];

        // Check whether this prefix sum has appeared before
        int previousIndex = search(prefixSum);

        if (previousIndex != -1)
        {
            // Same prefix sum means the elements between
            // previousIndex + 1 and i have sum zero
            int length = i - previousIndex;

            // Update maximum length
            if (length > maxLength)
            {
                maxLength = length;
            }
        }
        else
        {
            // Store only the first occurrence
            insert(prefixSum, i);
        }
    }

    return maxLength;
}

int main()
{
    // Input array containing positive and negative integers
    int arr[] = {9, -3, 3, -1, 6, -5};

    // Calculate the size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the longest zero-sum subarray
    int result = longestZeroSumSubarray(arr, n);

    // Display the result
    printf("Length of Longest Subarray with Zero Sum: %d\n",
           result);

    return 0;
}
