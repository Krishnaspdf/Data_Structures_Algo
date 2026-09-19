#include <stdio.h>
#include <string.h>

// Reverse the entire string
void reverse(char str[], int start, int end)
{
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

// Reverse words and remove extra spaces
void reverseWords(char s[])
{
    int n = strlen(s);
    int i = 0, j = 0;

    // Remove extra spaces and keep single spaces
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;

        if (i >= n)
            break;

        if (j > 0)
            s[j++] = ' ';

        while (i < n && s[i] != ' ')
            s[j++] = s[i++];

    }

    s[j] = '\0';

    // Reverse the complete string
    reverse(s, 0, j - 1);

    // Reverse each individual word
    int start = 0;

    for (int k = 0; k <= j; k++)
    {
        if (s[k] == ' ' || s[k] == '\0')
        {
            reverse(s, start, k - 1);
            start = k + 1;
        }
    }
}

int main()
{
    char s[] = "  Hello World This is C  ";

    reverseWords(s);

    printf("Reversed string: %s\n", s);

    return 0;
}