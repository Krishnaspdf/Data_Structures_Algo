#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *adj[MAX];

void addEdge(int u, int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = malloc(sizeof(struct Node));
    newNode->vertex = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void shortestPath(int n) {
    int dist[MAX];
    int queue[MAX];
    int front = 0, rear = 0;

    // Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = -1;
    }

    // Source vertex
    dist[0] = 0;
    queue[rear++] = 0;

    // BFS
    while (front < rear) {
        int u = queue[front++];

        struct Node *temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }

            temp = temp->next;
        }
    }

    // Print shortest distances
    printf("Shortest distances:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }

    printf("Enter edges:\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    shortestPath(n);

    return 0;
}