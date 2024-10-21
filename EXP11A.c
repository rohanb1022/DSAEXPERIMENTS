#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// BFS function
void bfs(int adjMatrix[MAX][MAX], int start, int n) {
    bool visited[MAX] = { false }; // Visited array
    int queue[MAX], front = 0, rear = 0; // Queue for BFS
    int i;

    // Enqueue the starting vertex and mark as visited
    queue[rear++] = start;
    visited[start] = true;

    printf("BFS Traversal: ");

    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Explore all adjacent vertices of the current vertex
        for (i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;  // Enqueue the adjacent vertex
                visited[i] = true;  // Mark it as visited
            }
        }
    }
}

int main() {
    int adjMatrix[MAX][MAX], n, i, j, start;

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

    bfs(adjMatrix, start, n);

    return 0;
}
