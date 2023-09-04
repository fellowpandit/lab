#include <stdio.h>
#include <time.h>

#define MAX_VERTICES 10

// Function to choose the next vertex with minimum distance
int selectMinDistanceVertex(int distances[], int visited[], int numVertices) {
    int j = 1, min = 100, w;
    for (w = 1; w <= numVertices; w++) {
        if ((distances[w] < min) && (visited[w] == 0)) {
            min = distances[w];
            j = w;
        }
    }
    return j;
}

// Function to calculate the shortest path from vertex v to all other vertices
void shortestPath(int source, int adjacencyMatrix[][MAX_VERTICES], int distances[], int numVertices) {
    int w, u, i, num, visited[MAX_VERTICES];

    for (i = 1; i <= numVertices; i++) {
        visited[i] = 0;
        distances[i] = adjacencyMatrix[source][i];
    }
    visited[source] = 0;
    distances[source] = 999;

    for (num = 2; num <= numVertices; num++) {
        u = selectMinDistanceVertex(distances, visited, numVertices);
        visited[u] = 1;

        for (w = 1; w <= numVertices; w++) {
            if ((distances[u] + adjacencyMatrix[u][w]) < distances[w] && !visited[w]) {
                distances[w] = distances[u] + adjacencyMatrix[u][w];
            }
        }
    }
}

int main() {
    int i, j, adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], distances[MAX_VERTICES], numVertices, source;
    double elapsedTime;
    clock_t startTime, endTime;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= numVertices; i++) {
        for (j = 1; j <= numVertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    printf("\nEnter the source vertex: ");
    scanf("%d", &source);

    startTime = clock();
    shortestPath(source, adjacencyMatrix, distances, numVertices);
    endTime = clock();

    printf("\nShortest distances from source vertex %d:\n", source);
    for (i = 1; i <= numVertices; i++) {
        printf("%d to %d = %d\n", source, i, distances[i]);
    }

    elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("The time taken is %f seconds\n", elapsedTime);

    return 0;
}
