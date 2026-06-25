#include <stdio.h>

int main() {
    int isPrime = 1;
    int prime = 13
    ,i;

    if (prime < 2) {
        isPrime = 0;
    } else {
        for (i = 2; i * i <= prime; i++) {
            if (prime % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }

    if (isPrime == 0) {
        printf("Not Prime");
    } else {
        printf("Prime");
    }

    return 0;
}
