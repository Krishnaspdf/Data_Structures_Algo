#include <stdio.h>
#include <limits.h>

static inline int max(int x, int y) { return (x > y) ? x : y; }
static inline int min(int x, int y) { return (x < y) ? x : y; }

int kthElement(const int *a, int m, const int *b, int n, int k) {
    // Ensure binary search is performed on the smaller array
    if (m > n) {
        return kthElement(b, n, a, m, k);
    }

    int low = max(0, k - n);
    int high = min(k, m);

    while (low <= high) {
        int cut1 = low + (high - low) / 2;
        int cut2 = k - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

        int r1 = (cut1 == m) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n) ? INT_MAX : b[cut2];

        // Valid partition found
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = cut1 - 1; // Move left in 'a'
        } else {
            low = cut1 + 1;  // Move right in 'a'
        }
    }

    return -1;
}

int main() {
    int a[] = {2, 3, 6, 7, 9};
    int b[] = {1, 4, 8, 10};
    int m = sizeof(a) / sizeof(a[0]);
    int n = sizeof(b) / sizeof(b[0]);
    int k = 5;

    printf("The %d-th element is: %d\n", k, kthElement(a, m, b, n, k));

    return 0;
}
