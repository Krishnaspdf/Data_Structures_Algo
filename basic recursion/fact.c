#include<stdio.h>
/*
int sumof(int n){
    if (n <= 0)
        return 0;

    return n + sumof(n-1);
}

int main(){
    int n = 5;
    int s = sumof(n);
    printf("%d\n", s);
    return 0;
} */


int fact(int n){
    if (n <= 1)
        return 1;

    return n * fact(n-1);
}

int main(){
    int n = 5;
    int s = fact(n);
    printf("%d\n", s);
    return 0;
}
