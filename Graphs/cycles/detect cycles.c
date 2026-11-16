#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];

int bfs(int start, int v) {
    int queue[MAX][2];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear][0] = start;
    queue[rear++][1] = -1;

    while (front < rear) {
        int node = queue[front][0];
        int parent = queue[front++][1];

        for (int i = 0; i < v; i++) {
            if (adj[node][i]) {
                if (!visited[i]) {
                    visited[i] = 1;
                    queue[rear][0] = i;
                    queue[rear++][1] = node;
                }
                else if (i != parent) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main() {
    int v, e, u, w;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = adj[w][u] = 1;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i] && bfs(i, v)) {
            printf("Cycle detected\n");
            return 0;
        }
    }

    printf("No cycle detected\n");
    return 0;
}