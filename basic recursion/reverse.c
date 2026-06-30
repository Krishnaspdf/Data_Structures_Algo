#include <stdio.h>
/*
int main()
{
    int N = 5, arr[] = {5, 4, 3, 2, 1};
    int rev[N];
    for (int i = 0; i < N; i++)
    {
        rev[i] = arr[N - i - 1];
    }
    for (int i = 0; i < N; i++)
    {
        printf(" %d ", rev[i]);
    }
    return 0;
}
*/
int main(){
    
    int n = 5, arr[] = {5, 4, 3, 2, 1};
    int left = 0;
    int right = n - 1;
    while ( left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        arr[left++];
        arr[right--];
    }
    for ( int i = 0; i < n; i++){
        printf(" %d ", arr[i]);
    }
    return 0;
}