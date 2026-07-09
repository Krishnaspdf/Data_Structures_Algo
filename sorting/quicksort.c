#include <stdio.h>

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Last element is chosen as pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        // If current element is smaller than pivot
        if (arr[j] < pivot)
        {
            i++;

            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Place pivot in its correct sorted position
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort Function
void quicksort(int arr[], int low, int high)
{
    /*
    Quick Sort

    1. Select a pivot element.
    2. Move all smaller elements to the left of the pivot.
    3. Move all larger elements to the right of the pivot.
    4. Pivot reaches its correct sorted position.
    5. Repeat the same process for the left and right subarrays.

    Time Complexity
    Best    : O(n log n)
    Average : O(n log n)
    Worst   : O(n^2)

    Space Complexity
    Best/Average : O(log n)
    Worst        : O(n)
    */

    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int arr[50];
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n < 1 || n > 50)
    {
        printf("Invalid number of elements!\n");
        return 1;
    }
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}