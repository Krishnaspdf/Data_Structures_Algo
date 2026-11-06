#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int V;

void DFS(int city) {
    visited[city] = 1;

    for (int i = 0; i < V; i++) {
        if (adj[city][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int findCircleNum() {
    int provinces = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            provinces++;
            DFS(i);
        }
    }

    return provinces;
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Number of Provinces: %d\n", findCircleNum());

    return 0;
}