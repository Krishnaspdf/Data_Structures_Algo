#include <stdio.h>

int nums[] = {1, 2, 3};
int n = 3;

// Generate sum of every subset
void subsetSums(int index, int sum)
{
    // All elements processed
    if (index == n)
    {
        printf("%d ", sum);
        return;
    }

    // Include current element
    subsetSums(index + 1, sum + nums[index]);

    // Exclude current element
    subsetSums(index + 1, sum);
}

int main()
{
    printf("Sums of all subsets:\n");

    subsetSums(0, 0);

    return 0;
}