#include "tree.c"
int main(){
    node* root;
    int choice, data, found;
    initBST(&root);

    do {
        printf("\nBinary Search Tree Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Remove\n");
        printf("4. Preorder Traversal\n");
        printf("5. Inorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Count Nodes\n");
        printf("8. Level-wise Traversal\n");
        printf("9. Inorder Traversal Non-recursive\n");
        printf("10. Exit\n");
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
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 10);
    return 0;
}
