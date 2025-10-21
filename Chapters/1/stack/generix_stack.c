#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define OK 1
#define ERROR 0

typedef char SElemType;  // use char for string/parentheses. Change to int for postfix.

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
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
    if (S->top - S->base >= S->stacksize) {
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
    if (S->top == S->base) return ERROR;  // empty
    *e = *(--S->top);
    return OK;
}

// Check if stack empty
int StackEmpty(SqStack S) {
    return S.top == S.base;
}


void reverseString(char str[]) {
    SqStack S;
    InitStack(&S);

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        Push(&S, str[i]);
    }

    for (int i = 0; i < len; i++) {
        Pop(&S, &str[i]);
    }
}

int main() {
    char str[] = "hello";
    printf("Original: %s\n", str);
    reverseString(str);
    printf("Reversed: %s\n", str);
    return 0;
}

