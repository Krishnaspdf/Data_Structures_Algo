#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int original = num, temp = num;
    int digits = 0, sum = 0;

    while (temp != 0) {
        digits++;
        temp = temp / 10;
    }

    temp = num;

    while (temp != 0) {
        int digit = temp % 10;
        sum = sum + pow(digit, digits);
        temp = temp / 10;
    }

    return sum == original;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
