#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int V;

// DFS Traversal
void DFS(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < V; i++) {
        if (adj[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS Traversal
void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < V; i++) {
            if (adj[vertex][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int E, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges:\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("DFS Traversal: ");
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    DFS(0);

    printf("\nBFS Traversal: ");
    BFS(0);

    return 0;
}
