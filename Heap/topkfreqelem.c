#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int num;
    int freq;
} Element;

int compare(const void *a, const void *b) {
    return ((Element *)a)->num - ((Element *)b)->num;
}

void topKFrequent(int nums[], int n, int k) {
    Element arr[MAX];
    int count = 0;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < count; j++) {
            if (arr[j].num == nums[i]) {
                arr[j].freq++;
                found = 1;
                break;
            }
        }

        if (!found) {
            arr[count].num = nums[i];
            arr[count].freq = 1;
            count++;
        }
    }

    // Bucket sort
    int bucket[MAX][MAX] = {0};
    int size[MAX] = {0};

    for (int i = 0; i < count; i++) {
        int f = arr[i].freq;
        bucket[f][size[f]++] = arr[i].num;
    }

    printf("Top %d frequent elements: ", k);

    int found = 0;

    for (int i = n; i >= 1 && found < k; i--) {
        for (int j = 0; j < size[i] && found < k; j++) {
            printf("%d ", bucket[i][j]);
            found++;
        }
    }
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int n = 6, k = 2;

    topKFrequent(nums, n, k);

    return 0;
}