#include <stdio.h>
#include <string.h>

#define MAX 26

int adj[MAX][MAX];
int indegree[MAX];

void addEdge(int u, int v) {
    if (!adj[u][v]) {
        adj[u][v] = 1;
        indegree[v]++;
    }
}

void alienDictionary(char words[][100], int n, int k) {
    int queue[MAX];
    int front = 0, rear = 0;
    int count = 0;
    char result[MAX + 1];

    memset(adj, 0, sizeof(adj));
    memset(indegree, 0, sizeof(indegree));

    // Build graph by comparing adjacent words
    for (int i = 0; i < n - 1; i++) {
        int len1 = strlen(words[i]);
        int len2 = strlen(words[i + 1]);
        int j = 0;

        while (j < len1 && j < len2 &&
               words[i][j] == words[i + 1][j]) {
            j++;
        }

        if (j < len1 && j < len2) {
            int u = words[i][j] - 'a';
            int v = words[i + 1][j] - 'a';

            addEdge(u, v);
        }
        else if (len1 > len2) {
            printf("Alien order: \n");
            return;
        }
    }

    // Insert characters with indegree 0
    for (int i = 0; i < k; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    // Kahn's Algorithm
    while (front < rear) {
        int node = queue[front++];
        result[count++] = node + 'a';

        for (int i = 0; i < k; i++) {
            if (adj[node][i]) {
                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    result[count] = '\0';

    if (count == k)
        printf("Alien order: %s\n", result);
    else
        printf("Alien order: \n");
}

int main() {
    int n, k;
    char words[100][100];

    printf("Enter number of words and characters: ");
    scanf("%d %d", &n, &k);

    printf("Enter dictionary words:\n");

    for (int i = 0; i < n; i++)
        scanf("%99s", words[i]);

    alienDictionary(words, n, k);

    return 0;
}