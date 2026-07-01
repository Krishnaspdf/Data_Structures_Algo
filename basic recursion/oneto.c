#include <stdio.h>
/*
void recurse(int n)
{
    if (n == 0)
        return;

    recurse(n - 1);

    printf("%d ", n);
}

int main()
{
    int n;
    printf("Enter The Value Of N: ");
    scanf("%d", &n);
    recurse(n);
    return 0;
} */

void recurse(int n)
{
    if (n == 0)
        return;

    printf("%d ", n);
    recurse(n - 1);
}

int main()
{
    int n;
    printf("Enter The Value Of N: ");
    scanf("%d", &n);
    recurse(n);
    return 0;
}