#include <stdio.h>

void heapify(int nums[], int n, int ind) {
    int smallest = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;

    if (left < n && nums[left] < nums[smallest])
        smallest = left;

    if (right < n && nums[right] < nums[smallest])
        smallest = right;

    if (smallest != ind) {
        int temp = nums[ind];
        nums[ind] = nums[smallest];
        nums[smallest] = temp;

        heapify(nums, n, smallest);
    }
}

void updateValue(int nums[], int n, int ind, int val) {
    nums[ind] = val;

    // Restore the min-heap property
    if (ind > 0 && nums[ind] < nums[(ind - 1) / 2]) {
        // Move the updated value upward
        while (ind > 0 && nums[ind] < nums[(ind - 1) / 2]) {
            int parent = (ind - 1) / 2;

            int temp = nums[ind];
            nums[ind] = nums[parent];
            nums[parent] = temp;

            ind = parent;
        }
    } else {
        // Move the updated value downward
        heapify(nums, n, ind);
    }
}

int main() {
    int nums[] = {1, 3, 5, 7, 9, 6};
    int n = sizeof(nums) / sizeof(nums[0]);

    int ind = 2;
    int val = 2;

    updateValue(nums, n, ind, val);

    printf("Updated min-heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", nums[i]);

    return 0;
}