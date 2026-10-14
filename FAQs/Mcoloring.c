#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int color[MAX];
int N, M;

// Check whether a color can be assigned to a vertex
int isSafe(int vertex, int c)
{
    for (int i = 0; i < N; i++)
    {
        if (graph[vertex][i] && color[i] == c)
            return 0;
    }

    return 1;
}

// Assign colors using backtracking
int graphColoring(int vertex)
{
    // All vertices are colored
    if (vertex == N)
        return 1;

    // Try each available color
    for (int c = 1; c <= M; c++)
    {
        if (isSafe(vertex, c))
        {
            color[vertex] = c;

            if (graphColoring(vertex + 1))
                return 1;

            // Backtrack
            color[vertex] = 0;
        }
    }

    return 0;
}

int main()
{
    N = 4;
    M = 3;

    // Initialize adjacency matrix
    int edges[][2] = {
        {0, 1}, {0, 2}, {1, 2},
        {1, 3}, {2, 3}
    };

    int E = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    if (graphColoring(0))
        printf("True: Graph can be colored using %d colors.\n", M);
    else
        printf("False: Graph cannot be colored using %d colors.\n", M);

    return 0;
}