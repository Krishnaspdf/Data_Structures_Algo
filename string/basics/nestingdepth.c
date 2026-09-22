#include <stdio.h>

int maxDepth(char* s) {
    int currentDepth = 0;
    int maxDepth = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        // Opening parenthesis increases the current nesting depth
        if (s[i] == '(') {
            currentDepth++;

            // Update maximum depth if necessary
            if (currentDepth > maxDepth) {
                maxDepth = currentDepth;
            }
        }

        // Closing parenthesis decreases the current nesting depth
        else if (s[i] == ')') {
            currentDepth--;
        }
    }

    return maxDepth;
}
