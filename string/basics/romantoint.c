#include <stdio.h>
#include <string.h>

// Return value of a Roman numeral
int value(char c)
{
    switch (c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }

    return 0;
}

// Convert Roman numeral to integer
int romanToInt(char s[])
{
    int result = 0;
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        // If current value is smaller than next value, subtract it
        if (i + 1 < n && value(s[i]) < value(s[i + 1]))
            result -= value(s[i]);
        else
            result += value(s[i]);
    }

    return result;
}

int main()
{
    char s[] = "III";

    printf("Integer: %d\n", romanToInt(s));

    return 0;
}