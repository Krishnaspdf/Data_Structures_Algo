/*Example 1:
Input:
 nums = [1, 2, 3, 4, 5]  
Output:
 [2, 3, 4, 5, 1]  
Explanation:
 Initially, nums = [1, 2, 3, 4, 5]  
Rotating once to the left results in nums = [2, 3, 4, 5, 1].*/
#include <stdio.h>
/* Rotate Left By One!*/
/*
int main(){
    int nums[] ={1, 2, 3, 4, 5};
    int n = sizeof(nums)/sizeof(nums[0]);
    int temp = nums[0];
    printf("Before Shift: \n");
    for ( int j=0; j < n; j++){
        printf("%d ", nums[j]);
    }
    printf("\n");
    for ( int i = 1; i < n ; i++){
        nums[i-1] = nums[i];
    }
    nums[n-1] = temp;
    printf("After Shift: \n");
    for ( int j=0; j < n; j++){
        printf("%d ", nums[j]);
    }
}
*/

/*Input : nums = [1, 2, 3, 4, 5, 6, 7], k = 2, left
Output : [6, 7, 1, 2, 3, 4, 5]
Explanation : rotate 1 step to the right: [7, 1, 2, 3, 4, 5, 6]
rotate 2 steps to the right: [6, 7, 1, 2, 3, 4, 5] 

Input : nums = [1, 2, 3, 4, 5, 6], k=2, left
Output : [3, 4, 5, 6, 1, 2]
Explanation :rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]*/
/*
int main(){
    int nums[] = {1, 2, 3, 4, 5, 6, 7}, k = 9;
    int n = sizeof(nums)/sizeof(nums[0]);
    int temp[] = {nums[0],nums[1]};

    if ( k > n){
        k = k % n;
    }

    for ( int i = k; i < n; i++){
        nums[i-k] = nums[i];
    }
    
    for ( int i = 0; i < 2; i++){
        nums[n-k] = temp[i];
        k--;
    }

    for ( int j=0; j < n; j++){
        printf("%d ", nums[j]);
    }

} */

/*  Left -> {1, 2, 3, 4, 5, 6, 7} -> {2,1,7,6,5,4,3} -> {3,4,5,6,7,1,2}
    Right -> {1, 2, 3, 4, 5, 6, 7} -> {5,4,3,2,1,7,6} -> {6,7,1,2,3,4,5}*/
void rotateight(int nums[], int n, int k) {
    int temp[n];  // valid temp array of size n

    // Right rotate: element at i goes to (i + k) % n
    for (int i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }

    // Copy back to nums
    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

void rotateleft(int nums[], int n, int k) {
    int temp[n];

    // Left rotate: element at i goes to (i - k + n) % n
    // or equivalently: element at (i + k) % n moves to i
    for (int i = 0; i < n; i++) {
        temp[i] = nums[(i + k) % n];
    }

    for (int i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    int n = sizeof(nums) / sizeof(nums[0]);

    if (k > n) {
        k = k % n;
    }

    // Rotate left
    rotateleft(nums, n, k);
    // After left rotate by 2: {3,4,5,6,7,1,2}
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // Rotate right on the same array
    rotateight(nums, n, k);
    // After right rotate by 2 on {3,4,5,6,7,1,2}: {1,2,3,4,5,6,7}
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}


















