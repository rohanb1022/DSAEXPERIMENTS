#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// DFS function
void dfs(int adjMatrix[MAX][MAX], int start, bool visited[MAX], int n) {
    printf("%d ", start); // Print the current vertex
    visited[start] = true; // Mark the current vertex as visited

    // Explore all adjacent vertices of the current vertex
    for (int i = 0; i < n; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            dfs(adjMatrix, i, visited, n); // Recursively visit each unvisited adjacent vertex
        }
    }
}

int main() {
    int adjMatrix[MAX][MAX], n, i, j, start;
    bool visited[MAX] = { false }; // Visited array

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    // Input the starting vertex
    printf("Enter the starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    // Call DFS function
    printf("DFS Traversal: ");
    dfs(adjMatrix, start, visited, n);

    return 0;
}
