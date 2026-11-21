#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];

int canFinish(int n) {
    int queue[MAX];
    int front = 0, rear = 0;
    int count = 0;

    // Insert vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    // BFS (Kahn's Algorithm)
    while (front < rear) {
        int node = queue[front++];
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    return count == n;
}

int main() {
    int n, e, a, b;

    printf("Enter number of tasks and prerequisites: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &a, &b);

        adj[b][a] = 1;
        indegree[a]++;
    }

    if (canFinish(n))
        printf("True");
    else
        printf("False");

    return 0;
}