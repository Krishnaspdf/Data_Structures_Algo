/*Problem Statement: Given an integer N, return the number of digits in N.*/
#include <stdio.h>
#include <math.h>

int countDigits(int n)
{

    int cnt = (int)(log10(n) + 1);
    return cnt;
}

int main()
{
    int N = 329823;
    printf("N: %d\n", N);
    int digits = countDigits(N) ;
    printf("Number Of Digits: %d", digits);
    return 0;
}


/* Otherwise:
int countDigits(int n)
{
    int cnt = 0;
    while(n>0){
    n = n / 10;
    cnt++;
}
    return cnt;
}*/
