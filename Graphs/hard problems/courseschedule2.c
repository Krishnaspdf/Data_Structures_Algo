#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];

int topologicalSort(int n, int result[]) {
    int queue[MAX];
    int front = 0, rear = 0;
    int count = 0;

    // Insert vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    // Perform BFS
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    // Return 0 if cycle exists
    if (count != n)
        return 0;

    return count;
}

int main() {
    int n, e, a, b;
    int result[MAX];

    printf("Enter number of tasks and prerequisites: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);

        adj[b][a] = 1;
        indegree[a]++;
    }

    int count = topologicalSort(n, result);

    if (count == 0) {
        printf("Empty array");
    } else {
        printf("Task order: ");

        for (int i = 0; i < count; i++)
            printf("%d ", result[i]);
    }

    return 0;
}