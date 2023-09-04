#include <stdio.h>
#include <time.h>

double elapsedTime;
clock_t startTime, endTime;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floydWarshall(int n, int graph[10][10], int shortestPath[10][10]) {
    int i, j, k;

    // Initialize the shortest path matrix with the given graph
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            shortestPath[i][j] = graph[i][j];
        }
    }

    // Calculate shortest paths using Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                shortestPath[i][j] = min(shortestPath[i][j], shortestPath[i][k] + shortestPath[k][j]);
            }
        }
    }
}

int main() {
    int i, j, n;
    int shortestPath[10][10], graph[10][10];

    printf("Enter the number of vertices: \n");
    scanf("%d", &n);
    printf("Enter the cost matrix: \n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    startTime = clock();
    floydWarshall(n, graph, shortestPath);
    endTime = clock();

    elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("All pair shortest path matrix is\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", shortestPath[i][j]);
        }
        printf("\n");
    }

    printf("\nThe run time is %f seconds\n", elapsedTime);

    return 0;
}
