#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for a stack node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(Node **top, int data) {
    Node *newNode = createNode(data);
    newNode->next = *top; // Link the new node to the previous top
    *top = newNode;       // Update top pointer
}

// Function to check if stack is empty
bool isEmpty(Node *top) {
    return (top == NULL);
}

// Function to pop an element from the stack
int pop(Node **top) {
    if (isEmpty(*top)) {
        printf("Stack underflow! Cannot pop from empty stack.\n");
        return -1;
    }
    Node *temp = *top;
    int popped = temp->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}

// Function to display all elements in the stack
void display(Node *top) {
    if (isEmpty(top)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    Node *temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    Node *top = NULL; // Initialize an empty stack

    printf("Input some elements onto the stack (using linked list):\n");
    push(&top, 6);
    push(&top, 5);
    push(&top, 3);
    push(&top, 1);
    display(top);

    printf("Remove 2 elements from the stack:\n");
    pop(&top);
    pop(&top);
    display(top);

    printf("Input 2 more elements:\n");
    push(&top, 8);
    push(&top, 9);
    display(top);

    // Free all nodes
    while (!isEmpty(top))
        pop(&top);

    return 0;
}
