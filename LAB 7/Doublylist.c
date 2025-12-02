#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;


struct Node* createNode(int val) {
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}


void insertBegin(int val) {
    struct Node* n = createNode(val);
    if(head != NULL) {
        n->next = head;
        head->prev = n;
    }
    head = n;
}

void insertEnd(int val) {
    struct Node* n = createNode(val);
    if(head == NULL) {
        head = n;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void insertPos(int val, int pos) {
    if(pos == 1) {
        insertBegin(val);
        return;
    }
    struct Node* temp = head;
    for(int i=1; i<pos-1 && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL) return;

    struct Node* n = createNode(val);
    n->next = temp->next;
    n->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = n;
    temp->next = n;
}


void deleteBegin() {
    if(head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    if(head != NULL) head->prev = NULL;
    free(temp);
}


void deleteEnd() {
    if(head == NULL) return;
    struct Node* temp = head;

    if(temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}


void deletePos(int pos) {
    if(head == NULL) return;

    if(pos == 1) {
        deleteBegin();
        return;
    }

    struct Node* temp = head;
    for(int i=1; i<pos && temp!=NULL; i++)
        temp = temp->next;

    if(temp == NULL) return;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}
void deletevalue(int val){
    if(head==NULL){return;}
    struct Node* temp= head;
    while(temp!=NULL && temp->data!=val ){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Value not found");
        return;
    }
    if(temp->data==val){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }

}
void display() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Position\n");
        printf("10. delete the value");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertBegin(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPos(value, pos);
                break;

            case 4:
                deleteBegin();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;

            case 7:
                display();
                break;
            case 10:
                printf("enter the value:");
                scanf("%d",&value);
                deletevalue(value);
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}

