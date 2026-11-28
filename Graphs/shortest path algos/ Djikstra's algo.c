#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define INF 109

struct Node {
    int vertex;
    int weight;
    struct Node *next;
};

struct HeapNode {
    int vertex;
    int distance;
};

struct Node *adj[MAX];

struct HeapNode heap[MAX * MAX];
int heapSize = 0;

// Add undirected edge
void addEdge(int u, int v, int w) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = malloc(sizeof(struct Node));

    newNode->vertex = u;
    newNode->weight = w;
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Swap heap elements
void swap(struct HeapNode *a, struct HeapNode *b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into min heap
void insertHeap(int vertex, int distance) {
    int i = heapSize++;

    heap[i].vertex = vertex;
    heap[i].distance = distance;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].distance <= heap[i].distance)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

// Remove minimum element
struct HeapNode extractMin() {
    struct HeapNode min = heap[0];

    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heapSize &&
            heap[left].distance < heap[smallest].distance)
            smallest = left;

        if (right < heapSize &&
            heap[right].distance < heap[smallest].distance)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return min;
}

// Dijkstra's algorithm
void dijkstra(int V, int S) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[S] = 0;

    heapSize = 0;
    insertHeap(S, 0);

    while (heapSize > 0) {
        struct HeapNode current = extractMin();

        int u = current.vertex;
        int d = current.distance;

        // Ignore outdated heap entries
        if (d > dist[u])
            continue;

        struct Node *temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                insertHeap(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    printf("Shortest distances:\n");

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);

}

int main() {
    int V, E, S;

    printf("Enter vertices, edges and source: ");
    scanf("%d %d %d", &V, &E, &S);

    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        addEdge(u, v, w);
    }

    dijkstra(V, S);

    return 0;
}