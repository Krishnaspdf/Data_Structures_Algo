#include <stdio.h>
#include <stdbool.h>

bool isMinHeap(int nums[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check the left child
        if (left < n && nums[i] > nums[left])
            return false;

        // Check the right child
        if (right < n && nums[i] > nums[right])
            return false;
    }

    return true;
}

int main() {
    int nums[] = {10, 20, 15, 30, 40, 25, 18};
    int n = sizeof(nums) / sizeof(nums[0]);

    if (isMinHeap(nums, n))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}