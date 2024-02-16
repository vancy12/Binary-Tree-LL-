#include "tree.c"
int main(){
    node* root;
    int choice, data, found;
    initBST(&root);

    do {
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1.  Insert\n");
        printf("2.  Search\n");
        printf("3.  Remove\n");
        printf("4.  Preorder Traversal\n");
        printf("5.  Inorder Traversal\n");
        printf("6.  Postorder Traversal\n");
        printf("7.  Count Nodes\n");
        printf("8.  Level-wise Traversal\n");
        printf("9.  Inorder Traversal Non-recursive\n");
        printf("10. Postorder Traversal Non-recursive\n");
        printf("11. Preorder Traversal Non-recursive\n");
        printf("12. Height of tree\n");
        printf("13. Height of a node\n");
        printf("14. Depth of a node\n");
        printf("15. Find maximum(BT)\n");
        printf("16. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                found = search(&root, data);
                if (found)
                    printf("Element found in the tree.\n");
                else
                    printf("Element not found in the tree.\n");
                break;
            case 3:
                printf("Enter data to remove: ");
                scanf("%d", &data);
                root = removeNode(root, data);
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Number of nodes in the tree: %d\n", count(root));
                break;
            case 8:
                printf("Level-wise Traversal: ");
                levelWise(root);
                break;
            case 9:
                printf("Inorder Traversal Non recursive: ");
                inorderNonRecursive(root);
                printf("\n");
                break;
            case 10:
                printf("Postorder Traversal Non recursive: ");
                postorderNonRecursive(root);
                printf("\n");
                break;
            case 11:
                printf("Preorder Traversal Non recursive: ");
                preorderNonRecursive(root);
                printf("\n");
                break;
            case 12:
                printf("Height of tree: ");
                printf("%d", heightOfTree(root));
                break;
            case 13:
                printf("Enter node whose height you want:");
                scanf("%d", &data);
                node* p = root;
                while(p){
                    if(data < p->data)
                        p = p->left;
                    else if(data > p->data) 
                        p = p->right;
                    else
                        break;
                }
                printf("Height of %d is %d\n", data,heightOfTree(p));
                break;
            case 14:
                printf("Enter node whose depth you want:");
                scanf("%d", &data);
                depthOfNode(root, data);
                break;
            case 15:
                printf("maximum is %d", findMax(root, INT32_MIN));
                break;
            case 16:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 16);
    return 0;
}
