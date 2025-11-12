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

// Function to check if stack is empty
bool isEmpty(Node *top) {
    return (top == NULL);
}

// Function to push an element onto the stack
void push(Node **top, int data) {
    Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
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

// Function to display the stack
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

// Function to reverse the stack
void reverseStack(Node **top) {
    Node *prev = NULL;
    Node *current = *top;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev one step ahead
        current = next;        // Move current one step ahead
    }

    *top = prev; // Update top pointer
}

// Main function
int main() {
    Node *top = NULL;

    printf("Input some elements onto the stack:\n");
    push(&top, 6);
    push(&top, 5);
    push(&top, 3);
    push(&top, 1);
    display(top);

    printf("Reverse the elements of the stack:\n");
    reverseStack(&top);
    display(top);

    // Free all nodes
    while (!isEmpty(top))
        pop(&top);

    return 0;
}
