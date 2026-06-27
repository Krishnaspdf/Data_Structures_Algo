/*Example 1:
Input: N = 5
Output: 0 1 1 2 3 5
Explanation: 0 1 1 2 3 5 is the fibonacci series up to 5th term.(0 based indexing)

Example 2:
Input: 6
Output: 0 1 1 2 3 5 8
Explanation: 0 1 1 2 3 5 8 is the fibonacci series upto 6th term.(o based indexing)*/

#include <stdio.h>
int fibonnaci(int n){
    if( n == 0){
       printf("0");
    }
    else if ( n == 1){
        printf("0  1");
    }
    else {
        int fib[n + 1];  
        fib[0] = 0;
        fib[1] = 1;

        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    return ;
    }
}
int main(){
int n;
printf("Enter Number Of Terms: ");
scanf("%d", n);
int x = fibonnaci(n);
printf("Series: ", x );
}