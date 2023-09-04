#include <stdio.h>
#include <time.h>

// Define a structure for representing edges
struct Edge {
    int u, v, cost;
};

typedef struct Edge Edge;

// Function to find the root of a vertex in a disjoint set
int find(int vertex, int parent[]) {
    while (parent[vertex] != vertex) {
        vertex = parent[vertex];
    }
    return vertex;
}

// Function to union two vertices in a disjoint set
void unionVertices(int i, int j, int parent[]) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

// Kruskal's algorithm to find the minimum spanning tree
void kruskal(int numVertices, Edge edges[], int numEdges) {
    int count, k, i, sum, u, v, j, tree[10][10], parent[10];
    Edge temp;
    count = 0;
    k = 0;
    sum = 0;

    // Sort edges in ascending order based on their costs
    for (i = 0; i < numEdges; i++) {
        for (j = 0; j < numEdges - 1; j++) {
            if (edges[j].cost > edges[j + 1].cost) {
                temp.u = edges[j].u;
                temp.v = edges[j].v;
                temp.cost = edges[j].cost;
                edges[j].u = edges[j + 1].u;
                edges[j].v = edges[j + 1].v;
                edges[j].cost = edges[j + 1].cost;
                edges[j + 1].u = temp.u;
                edges[j + 1].cost = temp.cost;
            }
        }
    }

    // Initialize disjoint set for vertices
    for (i = 0; i < numVertices; i++) {
        parent[i] = i;
    }

    int edgeIndex = 0;
    while (count != numVertices - 1) {
        u = edges[edgeIndex].u;
        v = edges[edgeIndex].v;
        i = find(u, parent);
        j = find(v, parent);

        if (i != j) {
            tree[k][0] = u;
            tree[k][1] = v;
            k++;
            count++;
            sum += edges[edgeIndex].cost;
            unionVertices(i, j, parent);
        }

        edgeIndex++;
    }

    if (count == numVertices - 1) {
        printf("A spanning tree exists\n");
        printf("The spanning tree is as follows:\n");
        for (i = 0; i < numVertices - 1; i++) {
            printf("%d  %d\t", tree[i][0], tree[i][1]);
        }
        printf("\nThe cost of the spanning tree is %d\n", sum);
    } else {
        printf("\nA spanning tree does not exist\n");
    }
}

int main() {
    int numVertices, numEdges, vertexA, vertexB, edgeCost;
    double elapsedTime;
    clock_t startTime, endTime;
    Edge edges[20];

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edge list (u  v  cost):\n");

    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &vertexA, &vertexB, &edgeCost);
        edges[i].u = vertexA;
        edges[i].v = vertexB;
        edges[i].cost = edgeCost;
    }

    startTime = clock();
    kruskal(numVertices, edges, numEdges);
    endTime = clock();
    elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    printf("The time taken is %f seconds\n", elapsedTime);

    return 0;
}
