#include <stdio.h>
#include <time.h>

void breadthFirstSearch(int adjacencyMatrix[10][10], int numVertices, int source) {
    int visited[10], queue[10], front = 0, rear = -1, currentNode, neighbor;

    // Initialize visited array to mark visited vertices
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }

    // Enqueue the source vertex and mark it as visited
    queue[++rear] = source;
    visited[source] = 1;

    // Perform BFS traversal
    while (front <= rear) {
        // Dequeue a vertex from the front of the queue
        currentNode = queue[front++];

        // Process the dequeued vertex and enqueue its unvisited neighbors
        for (neighbor = 0; neighbor < numVertices; neighbor++) {
            if (adjacencyMatrix[currentNode][neighbor] == 1 && visited[neighbor] == 0) {
                queue[++rear] = neighbor;
                printf("BFS traversal: %d -> %d\n", currentNode, neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

int main() {
    int adjacencyMatrix[10][10], numVertices, source;
    double executionTime;
    clock_t start_t, end_t;

    // Input the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input the adjacency matrix representing the graph
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Input the source vertex for BFS traversal
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    // Start measuring execution time
    start_t = clock();

    // Perform BFS traversal
    breadthFirstSearch(adjacencyMatrix, numVertices, source);

    // Stop measuring execution time
    end_t = clock();

    // Calculate and print the runtime in seconds
    executionTime = (double)(start_t - end_t) / CLOCKS_PER_SEC;
    printf("Runtime: %f seconds\n", executionTime);

    return 0;
}
