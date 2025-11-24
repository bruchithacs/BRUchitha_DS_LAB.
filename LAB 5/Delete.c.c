#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void createList(int n) {
    struct Node *newNode, *temp;
    int data, i;
    if (n <= 0) {
        printf("Number of nodes should be greater than 0. \n");
        return;
    }
    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed. \n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    printf("\nLinked list created successfully. \n");
}


void deleteAtFirst() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted %d from the end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}


void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted %d from position %d.\n", temp->data, pos);
        free(temp);
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    for (int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted %d from position %d.\n", temp->data, pos);
    free(temp);
}


void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Delete at Beginning\n");
        printf("2. Delete at End\n");
        printf("3. Delete at Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &data);
                createList(data);
                break;
            case 2:
                deleteAtFirst();
                break;
            case 3:
                deleteAtEnd();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
            }
    }
    return 0;
}