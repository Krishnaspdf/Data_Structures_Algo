#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX], path[MAX];

int dfs(int node, int v) {
    visited[node] = 1;
    path[node] = 1;

    for (int i = 0; i < v; i++) {
        if (adj[node][i]) {

            if (!visited[i]) {
                if (dfs(i, v))
                    return 1;
            }
            else if (path[i]) {
                return 1;
            }
        }
    }

    path[node] = 0;
    return 0;
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
        if (!visited[i] && dfs(i, v)) {
            printf("Cycle detected");
            return 0;
        }
    }

    printf("No cycle detected");

    return 0;
}