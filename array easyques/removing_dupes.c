#include <stdio.h>

int rem_dupes(int arr[], int n)
{
    if (n == 0)
        return 0;

    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}
int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = rem_dupes(arr, n);
    printf("Number of Unique Elements: %d\n", res);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < res; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}