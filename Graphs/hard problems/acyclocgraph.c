#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000
#define INF INT_MAX

struct Node {
    int vertex;
    int weight;
    struct Node *next;
};

struct Node *adj[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void addEdge(int u, int v, int w) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];

    adj[u] = newNode;
}

void dfs(int node) {
    visited[node] = 1;

    struct Node *temp = adj[node];

    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs(temp->vertex);
        }
        temp = temp->next;
    }

    stack[++top] = node;
}

void shortestPath(int n) {
    int dist[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[0] = 0;

    // Process vertices in topological order
    while (top != -1) {
        int u = stack[top--];

        if (dist[u] != INF) {
            struct Node *temp = adj[u];

            while (temp != NULL) {
                int v = temp->vertex;
                int w = temp->weight;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }

                temp = temp->next;
            }
        }
    }

    printf("Shortest distances:\n");

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges (source destination weight):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    // Generate topological ordering
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    shortestPath(n);

    return 0;
}