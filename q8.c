#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#define max 50

typedef struct {
    int head;
    int tail;
    int item[max];
}queue;

void queueinit(queue *q){
    q->head = -1;
    q->tail = -1;
}

bool isFull(queue *q){
    return q->tail==max-1;
}

bool isEmpty(queue *q){
    return q->head == q->tail;
}

void enqueue(queue *q,int ele){
    if(isFull(q)){
        printf("Queue Full");
        return;
    }
    q->item[++(q->tail)] = ele;
}

int dequeue(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue");
        return -1;
    }
    return q->item[++(q->head)];


}

int peek(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue");
        return -1;
    }
    return q->item[q->head +1];
}

void display(queue *q){
    if(isEmpty(q)){
        printf("Empty Queue");
        return ;
    }
    for(int i = q->head+1;i<=q->tail;i++){
        printf("%d ",q->item[i]);
    }
    printf("\n");
}

int main(){
    queue *q;
    queueinit(q);
    int n,ele,x;
    do{
        printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter choice:");
        scanf("%d",&n);
        printf("\n");
        switch(n){
            case 1:
                printf("Enter value to be enqueued");
                scanf("%d",&ele);
                enqueue(q,ele);
                printf("Successfully Enqueued");
                break;
            case 2:
                x = dequeue(q);
                printf("%d succesfully dequeued",x);
                break;
            case 3:
                x = peek(q);
                printf("Peeked Value %d",x);
                break;
            case 4:
                printf("Values in Queue");
                display(q);
                break;
            case 5:
                printf("Queue exited");
                

        }

    }while(n!=5);
}