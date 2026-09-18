#include <stdio.h>
#include <string.h>

// Remove outermost parentheses
void removeOuterParentheses(char s[], char result[])
{
    int balance = 0;
    int j = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            // Skip the outermost opening parenthesis
            if (balance > 0)
                result[j++] = s[i];

            balance++;
        }
        else
        {
            balance--;

            // Skip the outermost closing parenthesis
            if (balance > 0)
                result[j++] = s[i];
        }
    }

    result[j] = '\0';
}

int main()
{
    char s[] = "(()())(())";
    char result[100];

    removeOuterParentheses(s, result);

    printf("Result: %s\n", result);

    return 0;
}