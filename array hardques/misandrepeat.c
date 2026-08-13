#include <stdio.h>
/*
void findRepeatingAndMissing(const int nums[], int n, int result[2]) {
    long long expectedSum = (long long)n * (n + 1) / 2;
    long long expectedSquareSum =
        (long long)n * (n + 1) * (2LL * n + 1) / 6;

    long long actualSum = 0;
    long long actualSquareSum = 0;

    for (int i = 0; i < n; i++) {
        actualSum += nums[i];
        actualSquareSum += (long long)nums[i] * nums[i];
    }

    // difference = repeating - missing
    long long difference = actualSum - expectedSum;

    // squareDifference = repeating^2 - missing^2
    long long squareDifference = actualSquareSum - expectedSquareSum;

    // sum = repeating + missing
    long long sum = squareDifference / difference;

    long long repeating = (difference + sum) / 2;
    long long missing = sum - repeating;

    result[0] = (int)repeating;
    result[1] = (int)missing;
}

int main(void) {
    int nums[] = {1, 2, 2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result[2];

    findRepeatingAndMissing(nums, n, result);

    printf("Repeating number: %d\n", result[0]);
    printf("Missing number: %d\n", result[1]);

    return 0;
}
*/

void findRepeatingAndMissing(const int nums[], int n, int result[2]) {
    int xorAll = 0;

    // XOR array elements with numbers from 1 to n
    for (int i = 0; i < n; i++) {
        xorAll ^= nums[i];
        xorAll ^= (i + 1);
    }

    // Rightmost set bit
    int setBit = xorAll & -xorAll;

    int first = 0;
    int second = 0;

    // Divide array values into two groups
    for (int i = 0; i < n; i++) {
        if (nums[i] & setBit) {
            first ^= nums[i];
        } else {
            second ^= nums[i];
        }
    }

    // Divide numbers from 1 to n into the same two groups
    for (int value = 1; value <= n; value++) {
        if (value & setBit) {
            first ^= value;
        } else {
            second ^= value;
        }
    }

    // Identify which candidate is repeating
    int firstCount = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == first) {
            firstCount++;
        }
    }

    if (firstCount == 2) {
        result[0] = first;   // repeating
        result[1] = second;  // missing
    } else {
        result[0] = second;  // repeating
        result[1] = first;   // missing
    }
}

int main(void) {
    int nums[] = {1, 2, 2, 4};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result[2];

    findRepeatingAndMissing(nums, n, result);

    printf("Repeating number: %d\n", result[0]);
    printf("Missing number: %d\n", result[1]);

    return 0;
}
