#include <stdio.h>
#include <string.h>

#define SIZE 10007

// Structure for storing XOR value and its frequency
typedef struct
{
    int key;       // Prefix XOR value
    int frequency; // Number of times the XOR has occurred
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

// Insert XOR value or increase its frequency
void insert(int key)
{
    int position = hashFunction(key);

    // Handle collisions using linear probing
    while (hashTable[position].used &&
           hashTable[position].key != key)
    {
        position = (position + 1) % SIZE;
    }

    // If XOR value already exists, increase frequency
    if (hashTable[position].used)
    {
        hashTable[position].frequency++;
    }
    else
    {
        // Otherwise create a new entry
        hashTable[position].used = 1;
        hashTable[position].key = key;
        hashTable[position].frequency = 1;
    }
}

// Search for the frequency of an XOR value
int search(int key)
{
    int position = hashFunction(key);

    // Search for the required XOR value
    while (hashTable[position].used)
    {
        if (hashTable[position].key == key)
        {
            return hashTable[position].frequency;
        }

        position = (position + 1) % SIZE;
    }

    // XOR value not found
    return 0;
}

// Function to count subarrays having XOR equal to k
int countSubarrays(int A[], int n, int k)
{
    // Clear the hash table
    memset(hashTable, 0, sizeof(hashTable));

    int prefixXOR = 0;
    int count = 0;

    // Prefix XOR 0 occurs once before the array starts
    insert(0);

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        // Calculate prefix XOR
        prefixXOR = prefixXOR ^ A[i];

        // Required previous XOR:
        // prefixXOR ^ previousXOR = k
        // Therefore:
        // previousXOR = prefixXOR ^ k
        int requiredXOR = prefixXOR ^ k;

        // Add the number of times required XOR
        // has appeared before
        count += search(requiredXOR);

        // Store the current prefix XOR
        insert(prefixXOR);
    }

    return count;
}

int main()
{
    // Input array
    int A[] = {4, 2, 2, 6, 4};

    // Calculate size of the array
    int n = sizeof(A) / sizeof(A[0]);

    // Required XOR value
    int k = 6;

    // Count subarrays having XOR equal to k
    int result = countSubarrays(A, n, k);

    // Display the result
    printf("Number of subarrays with XOR %d: %d\n",
           k, result);

    return 0;
}
