#include <stdio.h>
#include <string.h>

// Find the beauty of the current substring
int getBeauty(int freq[])
{
    int maxFreq = 0;
    int minFreq = 1000000;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            if (freq[i] > maxFreq)
                maxFreq = freq[i];

            if (freq[i] < minFreq)
                minFreq = freq[i];
        }
    }

    return maxFreq - minFreq;
}

// Calculate sum of beauty of all substrings
int beautySum(char s[])
{
    int n = strlen(s);
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int freq[26] = {0};

        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            total += getBeauty(freq);
        }
    }

    return total;
}

int main()
{
    char s[] = "aabcb";

    printf("Sum of beauty: %d\n", beautySum(s));

    return 0;
}