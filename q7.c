#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>
#define Mazsize 50

typedef struct stack{
    int item[Mazsize];
    int top;
    
}stack;

void stackinit( stack *a){
    a->top = -1;

}

bool isFull(stack *a){
    return a->top == Mazsize-1;
}
bool isEmpty(stack *a){
    return a->top == -1;
}
void push(stack *a,int ele){
    if(isFull(a)){
        printf("Stack is Full cannot add");
    }
    else{
        a->item[++(a->top)] = ele;
        printf("Value Pushed Successfully");

    }
}

int pop(stack *a){
    if(isEmpty(a)){
        printf("Stack is Empty");
        return -1;
    }
    else{

        return a->item[(a->top)--];
    }
}

int peek(stack *a){
    if(isEmpty(a)){
        printf("Stack is Empty");
        return -1;
    }
    else{
        return a->item[a->top];
    }
}

void display(stack *a){

    if(isEmpty(a)){
        printf("Stack is Empty");
    }
    else{
        for(int i = 0;i<=a->top;i++){
            printf("%d ",a->item[i]);
        }
    }

}


int main(){

    stack *a;
    stackinit(a);
    printf("Enter number of brackets");
    int n;
    scanf("%d",&n);
    int ele;
    for(int i = 0;i<n;i++){
        scanf("%d",&ele);
        push(a,ele);    
    }
}
