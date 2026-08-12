#include <stdio.h>

// Function to merge nums2 into nums1
void merge(int nums1[], int m, int nums2[], int n)
{
    // i points to the last valid element of nums1
    int i = m - 1;

    // j points to the last element of nums2
    int j = n - 1;

    // k points to the last position of nums1
    int k = m + n - 1;

    // Compare elements from the end and place
    // the larger element at the end of nums1
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            j--;
        }

        k--;
    }

    // If elements are remaining in nums2,
    // copy them into nums1
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        j--;
        k--;
    }

    // Elements remaining in nums1 are already
    // in their correct positions
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main()
{
    // nums1 has m valid elements and n empty spaces
    int nums1[] = {1, 2, 3, 0, 0, 0};

    // Second sorted array
    int nums2[] = {2, 5, 6};

    int m = 3;
    int n = 3;

    // Merge nums2 into nums1
    merge(nums1, m, nums2, n);

    // Display the merged array
    printf("Merged Array: ");
    printArray(nums1, m + n);

    return 0;
}