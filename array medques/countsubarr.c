#include <stdio.h>
#include <string.h>

#define SIZE 10007

// Structure for Hash Map
typedef struct
{
    int key;
    int value;
    int used;
} HashNode;

HashNode hash[SIZE];

// Hash Function
int hashFunction(int key)
{
    if (key < 0)
        key = -key;
    return key % SIZE;
}

// Insert or update prefix sum frequency
void insert(int key)
{
    int index = hashFunction(key);

    while (hash[index].used && hash[index].key != key)
    {
        index = (index + 1) % SIZE;
    }

    if (hash[index].used)
    {
        hash[index].value++;
    }
    else
    {
        hash[index].used = 1;
        hash[index].key = key;
        hash[index].value = 1;
    }
}

// Get frequency of a prefix sum
int search(int key)
{
    int index = hashFunction(key);

    while (hash[index].used)
    {
        if (hash[index].key == key)
            return hash[index].value;

        index = (index + 1) % SIZE;
    }

    return 0;
}

// Function to count subarrays
int subarraySum(int nums[], int n, int k)
{
    memset(hash, 0, sizeof(hash));

    int prefixSum = 0;
    int count = 0;

    // Prefix sum 0 occurs once initially
    insert(0);

    for (int i = 0; i < n; i++)
    {
        prefixSum += nums[i];

        count += search(prefixSum - k);

        insert(prefixSum);
    }

    return count;
}

int main()
{
    int nums[] = {3, 1, 2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 6;

    printf("Number of Subarrays = %d\n", subarraySum(nums, n, k));

    return 0;
}
