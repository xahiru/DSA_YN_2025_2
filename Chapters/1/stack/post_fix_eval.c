#include <stdio.h>
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10
#define OK 1
#define ERROR 0

typedef int SElemTypeInt;

typedef struct {
    SElemTypeInt *base;
    SElemTypeInt *top;
    int stacksize;
} SqStackInt;

int InitStackInt(SqStackInt *S) {
    S->base = (SElemTypeInt *)malloc(STACK_INIT_SIZE * sizeof(SElemTypeInt));
    if (!S->base) return ERROR;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

int PushInt(SqStackInt *S, SElemTypeInt e) {
    if (S->top - S->base >= S->stacksize) {
        S->base = (SElemTypeInt *)realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(SElemTypeInt));
        if (!S->base) return ERROR;
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }
    *(S->top++) = e;
    return OK;
}

int PopInt(SqStackInt *S, SElemTypeInt *e) {
    if (S->top == S->base) return ERROR;
    *e = *(--S->top);
    return OK;
}

int StackEmptyInt(SqStackInt S) {
    return S.top == S.base;
}

// Evaluate postfix
int evaluatePostfix(char expr[]) {
    SqStackInt S;
    InitStackInt(&S);
    SElemTypeInt a, b, res;
    char *token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            PushInt(&S, atoi(token));
        } else {
            PopInt(&S, &b);
            PopInt(&S, &a);
            switch(token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            PushInt(&S, res);
        }
        token = strtok(NULL, " ");
    }
    PopInt(&S, &res);
    return res;
}
