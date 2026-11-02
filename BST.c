#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int value)
{
    struct node *newNode =
        (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = newNode->right = NULL;

    return newNode;
}

// Function to insert a node into BST
struct node* insert(struct node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);

        preorder(root->left);

        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct node* root)
{
    if (root != NULL)
    {
        postorder(root->left);

        postorder(root->right);

        printf("%d ", root->data);
    }
}

// Main Function
int main()
{
    struct node* root = NULL;

    int choice, value;

    while (1)
    {
        printf("\n--- Binary Search Tree Menu ---\n");

        printf("1: INSERT\n");
        printf("2: INORDER TRAVERSAL\n");
        printf("3: PREORDER TRAVERSAL\n");
        printf("4: POSTORDER TRAVERSAL\n");
        printf("5: EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("%d inserted into BST\n", value);
                break;

            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Try Again.\n");
        }
    }

    return 0;
}
