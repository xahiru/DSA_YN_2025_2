#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000 // Maximum size of stack

// Define Stack structure
struct Stack {
    int top;             // Index of top element
    int arr[MAX_SIZE];   // Array to store elements
};

// Function to initialize the stack
void initStack(struct Stack *s) {
    s->top = -1; // Initialize top index to -1 (empty stack)
}

// Function to push an element onto the stack
bool push(struct Stack *s, int x) {
    if (s->top >= MAX_SIZE - 1) {
        printf("Stack is full\n"); // Display message if stack is full
        return false; // Return false to indicate failure
    }
    s->arr[++(s->top)] = x; // Increment top index and add element
    return true; // Return true for success
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (s->top < 0) {
        printf("Stack underflow\n"); // Display message if stack is empty
        return 0; // Return 0 to indicate failure
    }
    return s->arr[(s->top)--]; // Return top element and decrement top
}

// Function to view the top element without removing it
int peek(struct Stack *s) {
    if (s->top < 0) {
        printf("Stack is empty\n"); // Display message if stack is empty
        return 0;
    }
    return s->arr[s->top]; // Return top element
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *s) {
    return (s->top < 0);
}

// Function to display stack elements
void display(struct Stack *s) {
    if (s->top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack elements: ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

// Main function
int main() {
    printf("Create a stack object:\n");
    struct Stack s;  // Declare a stack
    initStack(&s);   // Initialize it

    printf("Check if the stack is empty: %d\n", isEmpty(&s));

    printf("\nInsert some elements onto the stack:\n");
    push(&s, 7);
    push(&s, 6);
    push(&s, 5);
    push(&s, 4);
    display(&s);

    printf("\nRemove an element from the stack! %d\n", pop(&s));
    display(&s);

    printf("\nTop element of the stack:\n%d\n", peek(&s));

    return 0;
}
