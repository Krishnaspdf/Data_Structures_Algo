#include <stdio.h>
#include <string.h>

// Expand around the center and return palindrome length
int expand(char s[], int left, int right)
{
    while (left >= 0 && right < strlen(s) && s[left] == s[right])
    {
        left--;
        right++;
    }

    return right - left - 1;
}

// Find the longest palindromic substring
void longestPalindrome(char s[], char result[])
{
    int n = strlen(s);
    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++)
    {
        // Odd length palindrome
        int len1 = expand(s, i, i);

        // Even length palindrome
        int len2 = expand(s, i, i + 1);

        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen)
        {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    // Copy longest palindrome
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';
}

int main()
{
    char s[] = "babad";
    char result[100];

    longestPalindrome(s, result);

    printf("Longest palindromic substring: %s\n", result);

    return 0;
}