#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *stack;
int top = -1;
int max;

/* Check whether stack is empty */
bool isEmpty()
{
    return top == -1;
}

/* Check whether stack is full */
bool isFull()
{
    return top == max - 1;
}

/* PUSH operation */
void push()
{
    int value;

    if (isFull())
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter push item: ");
        scanf("%d", &value);

        top = top + 1;
        stack[top] = value;

        printf("%d pushed to stack\n", value);
    }
}

/* POP operation */
void pop()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d is popped out\n", stack[top]);
        top = top - 1;
    }
}

/* DISPLAY operation */
void display()
{
    int i;

    if (!isEmpty())
    {
        for (i = 0; i <= top; i++)
        {
            printf("stack[%d] = %d\n", i + 1, stack[i]);
        }
    }
    else
    {
        printf("Stack is empty\n");
    }
}

/* PEEK operation */
void peek()
{
    if (!isEmpty())
    {
        printf("Top element is: %d\n", stack[top]);
    }
    else
    {
        printf("Stack is empty\n");
    }
}

/* Main function */
int main()
{
    int choice;

    printf("Enter the maximum size of the stack: ");
    scanf("%d", &max);

    stack = (int *)malloc(max * sizeof(int));

    if (stack == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    do
    {
        printf("\n.................\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. QUIT\n");
        printf(".................\n");

        printf("Select your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                free(stack);
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid operation! Try again....\n");
        }

    } while (1);

    return 0;
}
