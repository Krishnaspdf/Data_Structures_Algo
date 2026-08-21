#include <stdio.h>

// Function to find floor and ceiling of x
void findFloorCeil(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    int floor = -1;
    int ceil = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If arr[mid] is equal to x,
        // it is both floor and ceiling
        if (arr[mid] == x)
        {
            floor = arr[mid];
            ceil = arr[mid];
            break;
        }

        // If arr[mid] is smaller than x,
        // it can be a possible floor
        if (arr[mid] < x)
        {
            floor = arr[mid];

            // Search for a larger value
            // that is still <= x
            low = mid + 1;
        }

        // If arr[mid] is greater than x,
        // it can be a possible ceiling
        else
        {
            ceil = arr[mid];

            // Search for a smaller value
            // that is still >= x
            high = mid - 1;
        }
    }

    printf("Floor = %d\n", floor);
    printf("Ceiling = %d\n", ceil);
}

int main()
{
    // Sorted input array
    int arr[] = {1, 2, 4, 6, 8, 10};

    // Calculate size of the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Target value
    int x = 5;

    // Find floor and ceiling
    findFloorCeil(arr, n, x);

    return 0;
}