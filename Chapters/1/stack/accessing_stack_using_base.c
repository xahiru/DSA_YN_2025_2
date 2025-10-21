#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 5
#define OK 1
#define ERROR 0

typedef char SElemType;  // you can change to int if needed

typedef struct {
    SElemType *base;   // pointer to base of stack
    SElemType *top;    // pointer to top of stack (one past last element)
    int stacksize;     // total allocated size
} SqStack;

// Initialize stack
int InitStack(SqStack *S) {
    S->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

// Push element
int Push(SqStack *S, SElemType e) {
    if (S->top - S->base >= S->stacksize) {  // stack full
        S->base = (SElemType *)realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if (!S->base) return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }
    *(S->top++) = e;
    return OK;
}

// Pop element
int Pop(SqStack *S, SElemType *e) {
    if (S->top == S->base) return ERROR;  // empty stack
    *e = *(--S->top);
    return OK;
}

// Check if stack is empty
int StackEmpty(SqStack S) {
    return S.top == S.base;
}

int main() {
    SqStack S;
    InitStack(&S);

    // Push some elements
    Push(&S, 'A');
    Push(&S, 'B');
    Push(&S, 'C');

    printf("Elements pushed: A, B, C\n");

    // Access elements directly via s.base[i]
    printf("Access using s.base[i]:\n");
    for (int i = 0; i < S.top - S.base; i++) {
        printf("S.base[%d] = %c\n", i, S.base[i]);
    }

    // Pop elements
    SElemType e;
    printf("\nPop elements:\n");
    while (!StackEmpty(S)) {
        Pop(&S, &e);
        printf("%c ", e);
    }
    printf("\n");

    // Free memory
    free(S.base);

    return 0;
}
