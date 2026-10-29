#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

bool isNStraightHand(int hand[], int handSize, int groupSize) {
    if (handSize % groupSize != 0)
        return false;

    qsort(hand, handSize, sizeof(int), compare);

    int i = 0;

    while (i < handSize) {
        if (hand[i] == -1) {
            i++;
            continue;
        }

        int first = hand[i];
        hand[i] = -1;

        int count = 1;

        for (int j = i + 1; j < handSize && count < groupSize; j++) {
            if (hand[j] == first + count) {
                hand[j] = -1;
                count++;
            }
        }

        if (count != groupSize)
            return false;

        i++;
    }

    return true;
}

int main() {
    int hand[] = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int handSize = sizeof(hand) / sizeof(hand[0]);
    int groupSize = 3;

    if (isNStraightHand(hand, handSize, groupSize))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}