/*
 * Find all elements appearing more than n/3 times in an array.
 * Uses Boyer-Moore voting (n/3 variant).
 * Time: O(n), Extra Space: O(1)
 */

#include <stdio.h>

/*
 * Returns count of majority elements and stores them in result[].
 * At most 2 elements can appear more than n/3 times.
 */
int majorityElements(int nums[], int n, int result[]) {
    int candidate1 = 0, candidate2 = 1;
    int count1 = 0, count2 = 0;

    /* First pass: find up to 2 candidates */
    for (int i = 0; i < n; i++) {
        int x = nums[i];

        if (count1 > 0 && x == candidate1) {
            count1++;
        } else if (count2 > 0 && x == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = x;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = x;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    /* Second pass: count actual frequencies of candidates */
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate1) count1++;
        else if (nums[i] == candidate2) count2++;
    }

    int idx = 0;
    int threshold = n / 3;

    if (count1 > threshold) result[idx++] = candidate1;
    if (count2 > threshold) result[idx++] = candidate2;

    return idx;
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int nums[] = {1, 2, 1, 1, 3, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result[2];

    int count = majorityElements(nums, n, result);

    printf("Input:  ");
    printArray(nums, n);
    printf("Output: ");
    printArray(result, count);

    return 0;
}
