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

// Function to display all stack elements
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

// Function to calculate the average value of stack elements
void CalculateAverage(SqStack S) {
    if (S.top == S.base) {
        printf("Stack is empty, cannot calculate average.\n");
        return;
    }

    int sum = 0, count = 0;
    for (SElemType *p = S.base; p < S.top; p++) {
        sum += *p;
        count++;
    }
    double avg = (double)sum / count;
    printf("Average value of stack elements: %.2f\n", avg);
}

// Main function
int main() {
    SqStack S;

    printf("Create a stack object:\n");
    InitStack(&S);

    printf("Insert some elements onto the stack:\n");
    Push(&S, 4);
    Push(&S, 5);
    Push(&S, 6);
    Push(&S, 7);
    DisplayStack(S);

    CalculateAverage(S);

    free(S.base);
    return 0;
}
