#include <stdio.h>

int visited[10];

void DFS(int graph[10][10], int n, int node) {
    visited[node] = 1;


    for(int i=0; i<n; i++) {
        if(graph[node][i] && !visited[i])
            DFS(graph, n, i);
    }
}

int main() {
    int n, connected = 1;
    int graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);

    // Initialize visited array
    for(int i=0; i<n; i++) visited[i] = 0;

    DFS(graph, n, 0); // Start DFS from vertex 0

    // Check if all vertices were visited
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            connected = 0;
            break;
        }
    }

    if(connected)
        printf("Graph is connected.\n");
    else
        printf("Graph is not connected.\n");

    return 0;
}
