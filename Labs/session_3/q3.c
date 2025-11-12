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
    if (!S->base) return false;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return true;
}

// Function to push an element onto the stack
bool Push(SqStack *S, SElemType e) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(SElemType));
        if (!S->base) return false;
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(S->top) = e;
    S->top++;
    return true;
}

// Function to display the stack
void DisplayStack(SqStack S) {
    if (S.top == S.base) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (SElemType *p = S.base; p < S.top; p++)
        printf("%d ", *p);
    printf("\n");
}

// Function to check if an element exists in the stack (used internally)
bool Exists(SqStack *S, SElemType e, int uptoIndex) {
    for (int i = 0; i < uptoIndex; i++) {
        if (S->base[i] == e)
            return true;
    }
    return false;
}

// Function to remove duplicate elements
void RemoveDuplicates(SqStack *S) {
    if (S->top == S->base) {
        printf("Stack is empty\n");
        return;
    }

    int uniqueCount = 0;
    for (int i = 0; i < (S->top - S->base); i++) {
        if (!Exists(S, S->base[i], uniqueCount)) {
            S->base[uniqueCount++] = S->base[i];
        }
    }
    S->top = S->base + uniqueCount;
}

// Main function
int main() {
    SqStack S;

    printf("Create a stack object:\n");
    InitStack(&S);

    printf("Insert elements onto the stack:\n");
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    Push(&S, 4);
    Push(&S, 7);
    Push(&S, 5);

    DisplayStack(S);

    printf("Remove duplicate elements:\n");
    RemoveDuplicates(&S);

    printf("Stack elements after removing duplicates: ");
    DisplayStack(S);

    free(S.base);
    return 0;
}
