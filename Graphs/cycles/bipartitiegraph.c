#include <stdio.h>

#define VMAX 1000
#define EMAX 100000

int head[VMAX], to[2 * EMAX], next[2 * EMAX];
int color[VMAX], idx = 0;

void addEdge(int u, int v) {
    to[idx] = v;
    next[idx] = head[u];
    head[u] = idx++;

    to[idx] = u;
    next[idx] = head[v];
    head[v] = idx++;
}

int isBipartite(int v) {
    int queue[VMAX];

    for (int i = 0; i < v; i++)
        color[i] = -1;

    for (int i = 0; i < v; i++) {
        if (color[i] != -1)
            continue;

        int front = 0, rear = 0;

        color[i] = 0;
        queue[rear++] = i;

        while (front < rear) {
            int node = queue[front++];

            for (int j = head[node]; j != -1; j = next[j]) {
                int adj = to[j];

                if (color[adj] == -1) {
                    color[adj] = 1 - color[node];
                    queue[rear++] = adj;
                }
                else if (color[adj] == color[node]) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main() {
    int v, e, u, w;

    scanf("%d %d", &v, &e);

    for (int i = 0; i < v; i++)
        head[i] = -1;

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }

    if (isBipartite(v))
        printf("Graph is Bipartite");
    else
        printf("Graph is not Bipartite");

    return 0;
}