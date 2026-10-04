#include <stdio.h>

// Generate binary strings without consecutive 1s
void generate(char str[], int pos, int n, int prev)
{
    // If string is complete, print it
    if (pos == n)
    {
        str[pos] = '\0';
        printf("%s\n", str);
        return;
    }

    // Place 0
    str[pos] = '0';
    generate(str, pos + 1, n, 0);

    // Place 1 only if previous character is not 1
    if (prev == 0)
    {
        str[pos] = '1';
        generate(str, pos + 1, n, 1);
    }
}

int main()
{
    int n = 3;
    char str[100];

    printf("Binary strings:\n");

    generate(str, 0, n, 0);

    return 0;
}