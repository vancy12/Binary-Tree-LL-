#include "header.h"

void initQueue(queue* Q){
    Q->front = NULL;
    Q->rear = NULL;
}

int queueEmpty(queue* Q){
    return(Q->front == NULL);
}

void enqueue(queue* Q, node* d){
    element* nn = (element*)malloc(sizeof(element));
    nn->store = d;
    nn->next = NULL;
    if(Q->front == NULL){
        Q->front = nn;
        Q->rear = nn;
        return;
    }
    else{
        Q->rear->next = nn;
        Q->rear = nn;
    }
}

node* dequeue(queue* Q){
    // no elements
    if(Q->front == NULL){
        return NULL;
    }
    // one element
    element* temp = Q->front;
    if(Q->front == Q->rear){
        Q->front = NULL;
        Q->rear = NULL;
        return temp->store;
    }

    Q->front = temp->next;
    return temp->store;
}
