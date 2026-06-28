/*Problem Statement: Given an integer N return the reverse of the given number.

Note: If a number has trailing zeros, then its reverse will not include them. For e.g , reverse of 10400 will be 401 instead of 00401.*/
/*
#include <stdio.h>
#include <math.h>

int reverse(int n){
    int rev = 0;
    while ( n != 0){
        int j = n % 10;
        rev = (rev * 10) + (j);
        n = n / 10;  
    }
    return rev;
}

int main(){
    int n = 40100;
    int result = reverse(n);  // Return value store karo
    printf("%d", result);
    return 0;
}
    */
#include <stdio.h>
#include <math.h>

int pallindrome(int n){
    int rev = 0;
    while ( n != 0){
        int j = n % 10;
        rev = (rev * 10) + (j);
        n = n / 10;  
    }
    return rev;
}

int main(){
    int n = 12321;
    int check = pallindrome(n);  // Return value store karo
    if ( check == n){
        printf("The Number %d Is Pallindrome", n);
    }
    else{
        printf("The Number %d Is not a Pallindrome", n);
    }
    return 0;
}
