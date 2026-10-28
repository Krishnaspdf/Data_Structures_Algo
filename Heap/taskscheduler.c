#include <stdio.h>

#define ALPHABET 26

int leastInterval(char tasks[], int tasksSize, int n) {
    int freq[ALPHABET] = {0};

    // Count the frequency of each task
    for (int i = 0; i < tasksSize; i++)
        freq[tasks[i] - 'A']++;

    // Build a max-heap of task frequencies
    int heap[ALPHABET];
    int size = 0;

    for (int i = 0; i < ALPHABET; i++) {
        if (freq[i] > 0)
            heap[size++] = freq[i];
    }

    // Build max-heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        int j = i;

        while (1) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest == j)
                break;

            int temp = heap[j];
            heap[j] = heap[largest];
            heap[largest] = temp;
            j = largest;
        }
    }

    int time = 0;

    while (size > 0) {
        int executed = 0;
        int remaining[ALPHABET];
        int count = 0;

        // Execute up to n+1 different tasks
        for (int i = 0; i <= n && size > 0; i++) {
            int current = heap[0];

            heap[0] = heap[--size];

            // Restore max-heap
            int j = 0;

            while (1) {
                int largest = j;
                int left = 2 * j + 1;
                int right = 2 * j + 2;

                if (left < size && heap[left] > heap[largest])
                    largest = left;

                if (right < size && heap[right] > heap[largest])
                    largest = right;

                if (largest == j)
                    break;

                int temp = heap[j];
                heap[j] = heap[largest];
                heap[largest] = temp;
                j = largest;
            }

            current--;
            if (current > 0)
                remaining[count++] = current;

            executed++;
        }

        // Reinsert tasks with remaining occurrences
        for (int i = 0; i < count; i++) {
            int j = size++;
            heap[j] = remaining[i];

            while (j > 0 && heap[(j - 1) / 2] < heap[j]) {
                int temp = heap[j];
                heap[j] = heap[(j - 1) / 2];
                heap[(j - 1) / 2] = temp;
                j = (j - 1) / 2;
            }
        }

        // Count the full cycle if tasks remain; otherwise count only executed tasks
        time += (size > 0) ? n + 1 : executed;
    }

    return time;
}

int main() {
    char tasks[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    int tasksSize = sizeof(tasks) / sizeof(tasks[0]);
    int n = 2;

    printf("Minimum CPU intervals: %d\n",
           leastInterval(tasks, tasksSize, n));

    return 0;
}