#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* largestOddNumber(char* s) {
    int len = strlen(s);
    int right = -1;

    // Step 1: Scan from right to left to find the first odd digit
    for (int i = len - 1; i >= 0; i--) {
        if ((s[i] - '0') % 2 != 0) {
            right = i;
            break;
        }
    }

    // If no odd digit is found, return an empty string
    if (right == -1) {
        char* result = (char*)malloc(1 * sizeof(char));
        result[0] = '\0';
        return result;
    }

    // Step 2: Skip leading zeros from the start
    int left = 0;
    while (left <= right && s[left] == '0') {
        left++;
    }

    // If everything up to the odd digit was zeros (e.g., "000")
    if (left > right) {
        char* result = (char*)malloc(1 * sizeof(char));
        result[0] = '\0';
        return result;
    }

    // Step 3: Allocate memory for the substring and copy it
    int sub_len = right - left + 1;
    char* result = (char*)malloc((sub_len + 1) * sizeof(char));
    
    strncpy(result, s + left, sub_len);
    result[sub_len] = '\0'; // Null-terminate the string

    return result;
}

int main() {
    // Example 1
    char s1[] = "05347";
    char* res1 = largestOddNumber(s1);
    printf("Input: %s -> Output: \"%s\"\n", s1, res1);
    free(res1); // Free dynamically allocated memory

    // Example 2
    char s2[] = "4206";
    char* res2 = largestOddNumber(s2);
    printf("Input: %s -> Output: \"%s\"\n", s2, res2);
    free(res2);

    return 0;
}
