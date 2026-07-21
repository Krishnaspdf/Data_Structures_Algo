#include <stdio.h>

void twoSum(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            printf("Pair found at indices %d and %d\n", left, right);
            printf("Values: %d + %d = %d\n", arr[left], arr[right], target);
            return;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    printf("No pair found.\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 8, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    twoSum(arr, n, target);

    return 0;
}
/*
Time complexity -> O(N)
Space Complexity - > O(1)*/
