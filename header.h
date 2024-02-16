#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct node{
    struct node *left;
    struct node *right;
    int data;
}node;

// stucture for queue
typedef struct element{
    node* store;
    struct element* next;
}element;

typedef struct queue{
    element* front;
    element* rear;
}queue;
// structure for stack
typedef struct stack{
    element* bottom;
}stack;

#endif // HEADER_H


