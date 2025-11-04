#include <stdio.h>
#define N 100

int queue[N];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        printf("Queue Overflow\n");
        return;
    } else if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = x;
    printf("%d inserted\n", x);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, x;
    while (1) {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid Choice\n");
        }
    }
}
