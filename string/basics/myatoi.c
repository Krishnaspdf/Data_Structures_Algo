#include <stdio.h>
#include <limits.h>
#include <ctype.h>

// Convert string to 32-bit signed integer
int myAtoi(char s[])
{
    int i = 0;
    int sign = 1;
    long long result = 0;

    // Step 1: Ignore leading spaces
    while (s[i] == ' ')
        i++;

    // Step 2: Check sign
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }

    // Step 3: Read digits
    while (isdigit(s[i]))
    {
        result = result * 10 + (s[i] - '0');

        // Step 4: Check overflow
        if (sign == 1 && result > INT_MAX)
            return INT_MAX;

        if (sign == -1 && -result < INT_MIN)
            return INT_MIN;

        i++;
    }

    return (int)(sign * result);
}

int main()
{
    char s[] = "   -42";

    printf("Integer: %d\n", myAtoi(s));

    return 0;
}