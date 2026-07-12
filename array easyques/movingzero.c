/*Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
Input : 1,2,0,1,0,4,0
Output: 1,2,1,4,0,0,0
Explanation : All the zeros are moved to the end and non-negative integers are moved to front by maintaining order
*/

#include <stdio.h>

int main() {
    int arr[] = {1, 0, 2, 3, 0, 4, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // pos: next position where a non-zero should be placed
    int pos = 0;

    // First pass: move all non-zeros to the front, preserving order
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[pos] = arr[i];
            pos++;
        }
    }

    // Second pass: fill the remaining positions with 0
    for (int i = pos; i < n; i++) {
        arr[i] = 0;
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(" , ");
    }
    printf("\n");

    return 0;
}
