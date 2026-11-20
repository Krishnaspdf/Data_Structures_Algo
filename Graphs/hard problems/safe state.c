#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int state[MAX];

int dfs(int node, int v) {
    state[node] = 1;

    for (int i = 0; i < v; i++) {
        if (adj[node][i]) {

            if (state[i] == 1)
                return 0;

            if (state[i] == 0 && !dfs(i, v))
                return 0;
        }
    }

    state[node] = 2;
    return 1;
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
        if (state[i] == 0)
            dfs(i, v);
    }

    printf("Safe nodes: ");

    for (int i = 0; i < v; i++) {
        if (state[i] == 2)
            printf("%d ", i);
    }

    return 0;
}