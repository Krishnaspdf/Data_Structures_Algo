#include <stdio.h>
#include <stdbool.h>

bool searchMatrix(int N, int M, const int mat[N][M], int target) {
    int low = 0;
    int high = (N * M) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / M;
        int col = mid % M;

        if (mat[row][col] == target) {
            return true;
        } else if (mat[row][col] < target) {
            low = mid + 1;  // Target lies in the right half
        } else {
            high = mid - 1; // Target lies in the left half
        }
    }

    return false;
}

int main() {
    int N = 3, M = 4;
    int mat[3][4] = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    if (searchMatrix(N, M, mat, target)) {
        printf("Target %d found in the matrix.\n", target);
    } else {
        printf("Target %d not found in the matrix.\n", target);
    }

    return 0;
}
