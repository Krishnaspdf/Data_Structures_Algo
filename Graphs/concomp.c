#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int V;

// DFS
void DFS(int vertex) {
    visited[vertex] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[vertex][i] && !visited[i]) {
            DFS(i);
        }
    }
}

// Count connected components
int countComponents() {
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            count++;
            DFS(i);
        }
    }

    return count;
}

int main() {
    int E, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter edges:\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("Connected Components: %d\n",
           countComponents());

    return 0;
}