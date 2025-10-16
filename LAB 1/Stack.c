#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
/*int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==N-1;
}*/

void push(){
    if(top==N-1){
        printf("Stack Overflow\n");
        return;
    }
    else{
        int x;
        printf("Enter the element to be pushed: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        printf("Pushed Element:%d \n",stack[top]);
        
    }
}

void pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return;
    }
    else{
        int item=stack[top];
        top--;
        printf("Popped element: %d \n",item);
    }
}
 void peek(){
    if (top==-1)
    {
       printf("Stack is Empty\n");
       return;
    }
    else{
        printf("Peek element of stack: %d \n",stack[top]);
    }
    
 }

 void display(){
    if(top==-1){
        printf("Stack is Empty\n");
        return;
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
    }
    printf("\n");
 }

 int main(){
    int choice;
    while(1){
        printf("1.Insert\n2.Delete\n3.Peek\n4.Display\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        default:
            printf("Invalid Choice\\n");
            break;
        }
        
    }
 }