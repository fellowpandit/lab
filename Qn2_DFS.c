#include<stdio.h>
#include<time.h>

void dfs(int numVertices, int adjacencyMatrix[10][10], int currentNode, int traversal[10][10], int visited[10]){
    static int numEdges = 0;

    //Since current Node is visited so, it is set to TRUE
    visited[currentNode] = 1;

    for(int neighbor = 0; neighbor < numVertices; neighbor++){
        if(adjacencyMatrix[currentNode][neighbor] == 1 && visited[neighbor] == 0){
            // Store the visited edge in the traversal array
            traversal[numEdges][0] = currentNode;
            traversal[numEdges][1] = neighbor;

            // Increasing the number of edges
            numEdges++;

            //Recursive call
            dfs(numVertices, adjacencyMatrix, neighbor, traversal, visited);
        }
    }
}

int main(){
    int numVertices, source, adjacencyMatrix[10][10], visited[10], traversal[10][10];
    clock_t start_t, end_t;

    printf("\n\t\t\t DEPTH FIRST SEARCH \n");
    printf("\n Enter number of vertices:");
    scanf("%d", &numVertices);

    // Opt to input adjacency matrix
    printf("\n Enter the adjacency matrix (Enter 0/1)\n");
    for(int i = 0; i < numVertices; i++)
        for(int j = 0; j < numVertices; j++)
            scanf("%d", &adjacencyMatrix[i][j]);

    //Opt to input source vertex
    printf("\n Enter the source vertex:");
    scanf("%d", &source);

    // Initialize visited array
    for(int i = 0; i < numVertices; i++){
        visited[i] = 0;
    }

    // Perform Depth First Search
    start_t = clock();
    dfs(numVertices, adjacencyMatrix, source, traversal, visited);
    end_t = clock();

    // Check reachability of vertices
    for(int i = 0; i < numVertices; i++){
        if(visited[i] == 1)
            printf("%d is reachable\n", i);
        else
            printf("%d is not reachable\n", i);
    }

    // Outputs the edges travelled
    printf("DFS traversal: Edges visited\n");
    for(int edge = 0; edge < numVertices - 1; edge++){
        printf("%d %d\n", traversal[edge][0], traversal[edge][1]);
    }

    // Calculate and print the runtime in seconds
    double executionTime = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("\n\nRuntime: %f seconds\n", executionTime);

    return 0;
}
