#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push element onto stack
void push(int x)
{
    stack[++top] = x;
}

// Pop element from stack
int pop()
{
    return stack[top--];
}

// Check if stack is empty
int isEmpty()
{
    return top == -1;
}

// Insert an element at the bottom of the stack
void insertAtBottom(int x)
{
    if (isEmpty())
    {
        push(x);
        return;
    }

    int temp = pop();

    insertAtBottom(x);

    push(temp);
}

// Reverse the stack using recursion
void reverseStack()
{
    if (isEmpty())
        return;

    int temp = pop();

    reverseStack();

    insertAtBottom(temp);
}

// Display stack
void display()
{
    if (isEmpty())
        return;

    int temp = pop();

    printf("%d ", temp);

    display();

    push(temp);
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    printf("Original stack (top to bottom): ");
    display();

    reverseStack();

    printf("\nReversed stack (top to bottom): ");
    display();

    return 0;
}