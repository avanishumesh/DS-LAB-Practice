#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    int head;
    int tail;
    int size;
    int *item;
}cqueue;

void queueinit(cqueue *c, int size){
    c->head = -1;
    c->tail = -1;
    c->size = size;
    c->item = (int *)malloc(size*sizeof(int));

    if(c->item == NULL){
        printf("No mememory Allocated");
    }

}
bool isFull(cqueue *c){
    return (c->tail + 1) % (c->size) == c->head;
}

bool isEmpty(cqueue *c){
    return c->head == -1;
}

void enqueue(cqueue *c,int ele){
    if(isFull(c)){
        printf("Queue is Full");
        return;
    }
    if(isEmpty(c)){
        c->head = 0;
    }
    c->tail = (c->tail+1)%c->size;
    c->item[c->tail] = ele;
}
int dequeue(cqueue *c){
    if(isEmpty(c)){
        printf("Queue is Empty");
        return -1;
    }
    int ele = c->item[c->head];
    if(c->head == c->tail){
        c->head = -1;
        c->tail = -1;
    }
    else{
        c->head = (c->head + 1)%c->size;
    }

    return ele;
}

void display(cqueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
int i = q->head;
    while (1) {
        printf("%d ", q->item[i]);
        if (i == q->tail) {
            break;
        }
        
        i = (i + 1) % q->size;
    }
    printf("\n");
}