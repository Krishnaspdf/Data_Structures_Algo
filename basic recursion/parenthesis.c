#include <stdio.h>

// Generate valid parentheses combinations
void generate(char result[], int pos, int open, int close, int n)
{
    // If string is complete, print it
    if (pos == 2 * n)
    {
        result[pos] = '\0';
        printf("%s\n", result);
        return;
    }

    // Add opening parenthesis
    if (open < n)
    {
        result[pos] = '(';
        generate(result, pos + 1, open + 1, close, n);
    }

    // Add closing parenthesis only when valid
    if (close < open)
    {
        result[pos] = ')';
        generate(result, pos + 1, open, close + 1, n);
    }
}

int main()
{
    int n = 3;
    char result[100];

    printf("Valid parentheses combinations:\n");

    generate(result, 0, 0, 0, n);

    return 0;
}