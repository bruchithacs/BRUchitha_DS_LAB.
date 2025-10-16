
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define N 100
char stack[N];
int top=-1;
 
void push(char x){
    if(top==N-1){
        printf("Stack Overflow\n");
    }
    else{
        stack[++top]=x;
    }
}

char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
    }else{
        return stack[top--];
    }
}

int precendence(char a){
    if(a=='^'){
        return 3;
    }else if(a=='*' || a=='/' || a=='%'){
        return 2;
    }else if(a=='+' || a=='-'){
        return 1;
    }else{
        return 0;
    }
}


int main(){
    char infix[N],postfix[N];
    int i; int k=0;
    char x;

    printf("Enter the infix expresssion: ");
    gets(infix);

    for(i=0;i< strlen(infix);i++){
        char ch=infix[i];

        if(isalnum(ch)){
            postfix[k++]=ch;
        }else if(ch=='('){
            push(ch);
        }else if(ch==')'){
            while((x=pop())!='('){
                postfix[k++]=x;
            }
        }
        else{
            while(precendence(stack[top])>=precendence(ch)){
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';

    printf("The Postfix Expression: %s ",postfix);
    return 0;
}
