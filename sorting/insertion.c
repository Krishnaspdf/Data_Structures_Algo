/*Example 1:
Input:
  nums = [7, 4, 1, 5, 3]  
Output:
  [1, 3, 4, 5, 7]  
Explanation:
  The array is sorted in non-decreasing order: 1 ≤ 3 ≤ 4 ≤ 5 ≤ 7.*/

#include <stdio.h>

int main(void)
{
    int arr[10], i, j, count, temp;
    printf("Enter number of elements: ");
    scanf("%d", &count);
    printf("Enter %d elements:\n", count);
    for (i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }
    // Insertion sort (ascending)
    for (i = 1; i < count; i++) {
        temp = arr[i];
        j = i - 1;
        while ((j >= 0) && (temp < arr[j])) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    printf("\nSorted elements are:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}