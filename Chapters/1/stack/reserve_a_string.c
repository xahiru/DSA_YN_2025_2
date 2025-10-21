#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char SElemType;

typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

#define STACK_INIT_SIZE 100

void InitStack(SqStack *S) {
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

int StackEmpty(SqStack *S) {
    return S->top == S->base;
}

void Push(SqStack *S, SElemType e) {
    *(S->top++) = e;
}

SElemType Pop(SqStack *S) {
    return *(--S->top);
}

void reverseString(char str[]) {
    SqStack S;
    InitStack(&S);

    for (int i = 0; str[i] != '\0'; i++)
        Push(&S, str[i]);

    int i = 0;
    while (!StackEmpty(&S))
        str[i++] = Pop(&S);

    free(S.base);
}

int main() {
    char str[] = "hello";
    printf("Original: %s\n", str);
    reverseString(str);
    printf("Reversed: %s\n", str);
    return 0;
}
