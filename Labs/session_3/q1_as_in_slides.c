#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int SElemType;

typedef struct {
    SElemType *base;    // Pointer to base of stack
    SElemType *top;     // Pointer to top of stack
    int stacksize;      // Current allocated size
} SqStack;

// Function to initialize the stack
bool InitStack(SqStack *S) {
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) return false; // Memory allocation failed
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return true;
}

// Function to check if stack is empty
bool StackEmpty(SqStack S) {
    return (S.top == S.base);
}

// Function to push an element onto the stack
bool Push(SqStack *S, SElemType e) {
    if (S->top - S->base >= S->stacksize) {
        // Reallocate more space
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) return false;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top) = e;
    S->top++;
    return true;
}

// Function to pop an element from the stack
bool Pop(SqStack *S, SElemType *e) {
    if (S->top == S->base) {
        printf("Stack underflow\n");
        return false;
    }
    S->top--;
    *e = *(S->top);
    return true;
}

// Function to get the top element
bool GetTop(SqStack S, SElemType *e) {
    if (S.top == S.base) {
        printf("Stack is empty\n");
        return false;
    }
    *e = *(S.top - 1);
    return true;
}

// Function to display the stack
void DisplayStack(SqStack S) {
    if (S.top == S.base) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (SElemType *p = S.top - 1; p >= S.base; p--)
        printf("%d ", *p);
    printf("\n");
}

// Main function
int main() {
    SqStack S;
    SElemType e;

    printf("Create a stack object:\n");
    InitStack(&S);

    printf("Check if the stack is empty: %d\n", StackEmpty(S));

    printf("\nInsert some elements onto the stack:\n");
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    Push(&S, 7);
    DisplayStack(S);

    printf("\nRemove an element from the stack! ");
    if (Pop(&S, &e))
        printf("%d\n", e);
    DisplayStack(S);

    printf("\nTop element of the stack:\n");
    if (GetTop(S, &e))
        printf("%d\n", e);

    // Free allocated memory
    free(S.base);

    return 0;
}
