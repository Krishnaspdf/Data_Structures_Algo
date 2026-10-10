#include <stdio.h>
#include <string.h>

char s[100];
char parts[100][100];
int n;

// Check whether a substring is a palindrome
int isPalindrome(int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            return 0;

        left++;
        right--;
    }

    return 1;
}

// Generate all palindrome partitions
void partition(int start, int index)
{
    // Entire string is partitioned
    if (start == n)
    {
        printf("[ ");

        for (int i = 0; i < index; i++)
            printf("%s ", parts[i]);

        printf("]\n");
        return;
    }

    for (int end = start; end < n; end++)
    {
        if (isPalindrome(start, end))
        {
            int len = end - start + 1;

            strncpy(parts[index], s + start, len);
            parts[index][len] = '\0';

            partition(end + 1, index + 1);
        }
    }
}

int main()
{
    strcpy(s, "aab");
    n = strlen(s);

    printf("Palindrome partitions:\n");
    partition(0, 0);

    return 0;
}