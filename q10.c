//circular hospital queue
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int size;
    int front;
    int rear;
    int *item;
}queue;


void init(queue *q,int size){
    q->rear = -1;
    q->front = -1;
    q->size = size;
    q->item = (int *)malloc(size*sizeof(int));
}

bool isFull(queue *q){

    return (q->rear + 1)%(q->size) == q->front;
    
}

bool isEmpty(queue *q){
    return q->front == -1;
}

void enqueue(queue *q, int ele){
    if(isFull(q)){
        printf("Queue is Full\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
        q->rear = 0;
    }
    else{
        q->rear = (q->rear +1)%q->size;
    }
        q->item[q->rear] = ele;
        printf("Enqueued successfully\n");
}

void dequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return ;
    }
    int x = q->item[q->front];
    
    if(q->front==q->rear){
        q->front = -1;
        q->rear = -1;
    
    }
    else{
        q->front = (q->front + 1)%q->size;
    }
    printf("%d Dequeued",x);

}
void prioritydequeue(queue *q){
    if(isEmpty(q)){
        printf("Queue is Empty");
        return ;
    }
    int smallest = q->item[q->front];
    int pos = q->front;
    int i = q->front;

while(i != q->rear){
    i = (i + 1) % q->size;

    if(smallest > q->item[i]){
        smallest = q->item[i];
        pos = i;
    }
}
     i = pos;
    while(i!=q->rear){
        int next = (i+1)%q->size;
        q->item[i] = q->item[next];
        i = next;

    }
    if(q->front == q->rear){
    q->front = -1;
    q->rear = -1;
}
else{
    q->rear = (q->rear - 1 + q->size) % q->size;
}
 }
void display(queue *q){
    if(isEmpty(q)){
        printf("Queue is empty nothing to display\n");
        return;
    }
    // 🔴 CHANGE
int i = q->front;

while(1){
    printf("%d ",q->item[i]);

    if(i == q->rear)
        break;

    i = (i + 1) % q->size;
}
printf("\n");

}

int main(){
    printf("Enter size of queue");
    int size;
    scanf("%d",&size);

    queue q;
    init(&q,size);
    int x;
    int y;

    do{
        printf("Enter Choice \n1.Enqueue \n2.Dequeue \n3.Priority Dequeue\n4.Display \n5.Exit\n");
        scanf("%d",&x);
        switch(x){
            case 1:
                    printf("Enter value to enqueue");
                    scanf("%d",&y);
                    enqueue(&q,y);
                    break;
            case 2:
                    dequeue(&q);
                    break;
            
            case 3:
                    prioritydequeue(&q);
                    break;
            case 4:
                    display(&q);
                    break;
            case 5:
                printf("Exited Successfully");
                break;
            
        }

    }while(x!=5);

}