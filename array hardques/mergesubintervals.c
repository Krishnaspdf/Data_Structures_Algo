#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct
{
    int start;
    int end;
} Interval;

// Comparator function for sorting intervals by start time
int compare(const void *a, const void *b)
{
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;

    return x->start - y->start;
}

// Function to merge overlapping intervals
void mergeIntervals(Interval intervals[], int n)
{
    // Sort intervals according to their starting point
    qsort(intervals, n, sizeof(Interval), compare);

    // Index for storing the last merged interval
    int index = 0;

    // Traverse all intervals
    for (int i = 1; i < n; i++)
    {
        // If current interval overlaps with the last merged interval
        if (intervals[i].start <= intervals[index].end)
        {
            // Extend the ending point if necessary
            if (intervals[i].end > intervals[index].end)
            {
                intervals[index].end = intervals[i].end;
            }
        }
        else
        {
            // No overlap, move to the next position
            index++;

            // Store the current interval
            intervals[index] = intervals[i];
        }
    }

    // Print the merged intervals
    printf("Merged Intervals:\n");

    for (int i = 0; i <= index; i++)
    {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }

    printf("\n");
}

int main()
{
    // Input intervals
    Interval intervals[] =
    {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    // Calculate the number of intervals
    int n = sizeof(intervals) / sizeof(intervals[0]);

    // Merge overlapping intervals
    mergeIntervals(intervals, n);

    return 0;
}