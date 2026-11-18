#include <stdio.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX];
int stack[MAX], top = -1;

void dfs(int node, int v) {
    visited[node] = 1;

    for (int i = 0; i < v; i++) {
        if (adj[node][i] && !visited[i])
            dfs(i, v);
    }

    stack[++top] = node;
}

int main() {
    int v, e, u, w;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        adj[u][w] = 1;
    }

    for (int i = 0; i < v; i++) {
        if (!visited[i])
            dfs(i, v);
    }

    printf("Topological Sort: ");

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}