#include "header.h"
void initStack(stack* S){
    S->bottom = NULL;
}

int isEmpty(stack S){
    return(S.bottom == NULL);
}

void push(stack* S, node* d){
    element* nn = (element*)malloc(sizeof(element));
    nn->next = NULL;
    nn->store = d;

    if(S->bottom == NULL){
        S->bottom = nn;
        return;
    }
    element* temp = S->bottom;
    S->bottom = nn;
    nn->next = temp;
    return;
}

node* pop(stack* S){
    if(isEmpty(*S)){
        return NULL;
    }
    element* temp = S->bottom;
    S->bottom = temp->next;
    return temp->store;
}

