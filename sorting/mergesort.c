#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;

    int n1 = mid - left + 1; //Formula to calc how many numbers in left arr
    int n2 = right - mid;//Formula to calc how many numbers in right arr

    int L[n1], R[n2];

    // Copy left half
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];

    // Copy right half
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // Merge both halves
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left half
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of right half
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; //or both works int mid = (left + right)/2; The longer version prevents integer overflow when indices are very large.

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}