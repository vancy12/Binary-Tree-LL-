#include "queue.c"
#include "stack.c"

void initBST(node** root){
    *root = NULL;
}

node* createNode(int d){
    node* nn = (node*)malloc(sizeof(node));
    nn->left = NULL;
    nn->right = NULL;
    nn->data = d;
    return nn;
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int count(node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

void insert(node** root, int d){
    // q keeps track of parent
    // p keeps track of child
    // so that when p reaches child node we can insert at q i.e. the parent
    node *p, *q;
    p = *root;
    if(p == NULL){
        *root = createNode(d);
        return;
    }

    while(p != NULL){
        q = p;
        if(p->data == d){
            printf("Duplicates cannot be present in a BST\n");
            return;
        }
        else if(d < p->data){
            p = p->left;
        }
        else{
            p = p->right;
        }
    }
    // here we reach the node where we want to insert the data
    if(d < q->data){
        q->left = createNode(d);
    }
    else{
        q->right = createNode(d);
    }
}

// return 1 if found...0 otherwise
int search(node** root, int find){
    node* p = *root;
    while(p != NULL){
        if(find < p->data){
            p = p->left;
        }
        else if(find > p->data){
            p = p->right;
        }
        else{
            // element found
            return 1;
        }
    }
    // element not found
    return 0;
}

node* removeNode(node* root, int remove){
    // traverse to the node to be deleted
    if(root == NULL){
        return root;
    }

    if(remove < root->data){
        root->left = removeNode(root->left, remove);
        return root;
    }
    else if(remove > root->data){
        root->right = removeNode(root->right, remove);
        return root;
    }
    // if node has 1 child
    if(root->right == NULL){
        node* temp = root->left;
        free(root);
        return temp;
    }
    else if(root->left == NULL){
        node* temp = root->right;
        free(root);
        return temp;
    }
    
    // if node has 2 children
    node* succParent = root;
    node* succ = root->right;

    while(succ->left != NULL){
        succParent = succ;
        succ = succ->left;
    }

    if(succParent != root){
        succParent->left = succ->right;
    }
    else{
        succParent->right = succ->right;
    }
    root->data = succ->data;
    free(succ);
    return root;

}

void levelWise(node* root){
    node* t = root;
    queue Q;
    initQueue(&Q);
    enqueue(&Q, root);

    while(!queueEmpty(&Q)){
        node* p = dequeue(&Q);
        printf("%d ", p->data);
        if(p->left)
            enqueue(&Q, p->left);
        if(p->right)
            enqueue(&Q, p->right);
    }
    printf("\n");
}

void inorderNonRecursive(node* root){
    stack S;
    initStack(&S);
    node* p = root;
    int flag = 1;
    while(flag){
        if(p){
            push(&S, p);
            p = p->left;
        }
        else{
            if(!isEmpty(S)){
                p = pop(&S);
                printf("%d ", p->data);
                p = p->right;
            }
            else{
                flag = 0;
            }
        }
    }
}

void postorderNonRecursive(node* root){
    stack S1, S2;
    initStack(&S1);
    initStack(&S2);
    node* p;

    push(&S1, root);
    while(!isEmpty(S1)){
        p = pop(&S1);
        push(&S2, p);
        if(p->left)
            push(&S1, p->left);
        if(p->right)
            push(&S1, p->right);
    }    
    while(!isEmpty(S2)){
        printf("%d ", pop(&S2)->data);
    }
}

void preorderNonRecursive(node* root) {
    stack S;
    // root node --> index is 0
    node* p = root;
    initStack(&S);
    push(&S, p);
    
    while(!isEmpty(S)){
        p = pop(&S);
        if(p) {
            printf("%d ", p->data); // Visit current node
            // Push right child first
            if(p->right)
                push(&S, p->right);
            // Push left child
            if(p->left)
                push(&S, p->left);
        }
    }
}

int heightOfTree(node* root){
    int leftSubtree, rightSubtree;
    if(root == NULL)
        return 0;
    else   
        leftSubtree = heightOfTree(root->left);
        rightSubtree = heightOfTree(root->right);
    
        return max(leftSubtree, rightSubtree) + 1;
}

void depthOfNode(node* root, int data){
    node* p = root;
    int depth = 1;
    while(p){
        if(data < p->data){
            p = p->left;
            depth++;
        }
        else if(data > p->data) {
            p = p->right;
            depth++;
        }
        else
            break;
    }
    printf("Depth of %d is %d\n", data, depth);
}

int findMax(node* root, int maximum){
    if(root == NULL)
        return 0;
    
    int left_val, right_val;
    left_val = findMax(root->left, maximum);
    right_val = findMax(root->right, maximum);
    maximum = max(max(left_val, right_val), root->data);

    return maximum;
}
