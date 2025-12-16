#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX-1) {
        printf("Queue Overflow\n");
    } else {
        if(front == -1) front = 0;
        queue[++rear] = x;
    }
}

int dequeue() {
    if(front == -1) {
        printf("Queue Underflow\n");
        return -1;
    } else {
        int x = queue[front];
        if(front == rear) front = rear = -1;
        else front++;
        return x;
    }
}

int isEmpty() {
    return front == -1;
}

void BFS(int graph[10][10], int n, int start) {
    int visited[10] = {0};
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");
    while(!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for(int i=0; i<n; i++) {
            if(graph[node][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    int graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &graph[i][j]);

    int start;
    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(graph, n, start);
    return 0;
}


