/*Example 1:
Input:
 [1, 2, 4, 7, 7, 5]  
Output:
  
Second Smallest : 2  
Second Largest : 5  
Explanation:
  The elements are sorted as 1, 2, 4, 5, 7, 7.  
Hence, the second smallest element is 2, and the second largest element is 5.

Example 2:
Input:
 [1]  
Output:
  
Second Smallest : -1  
Second Largest : -1  
Explanation:
  Since there is only one element in the array, it is both the largest and smallest element.  
Therefore, there is no second smallest or second largest element present.*/
#include <stdio.h>
#include <limits.h>

int seclargest(int arr[], int n)
{
    int largest = INT_MIN;
    int seclarg = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            seclarg = largest;
            largest = arr[i];
        }
        else if (arr[i] > seclarg && arr[i] != largest)
        {
            seclarg = arr[i];
        }
    }
    return seclarg;
}
int secsmallest(int arr[], int n)
{
    int smallest = INT_MAX;
    int secsmall = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            secsmall = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secsmall && arr[i] != smallest)
        {
            secsmall = arr[i];
        }
    }
    return secsmall;
}
int main()
{
    int arr[] = {1, 2, 4, 7, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Second Largest : %d\n", seclargest(arr, n));
    printf("Second Smallest: %d\n", secsmallest(arr, n));
    return 0;
}