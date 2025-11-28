#include <stdio.h>
#include "adt2_sstring.h"

void PrintSString(SString S) {
    for (int i = 1; i <= S[0]; i++)
        putchar(S[i]);
}

int main() {
    SString A, B, C, Sub;

    StrAssign(A, "Hello");
    StrAssign(B, "World!");

    printf("A = ");
    PrintSString(A);
    printf("\n");

    printf("B = ");
    PrintSString(B);
    printf("\n");

    // Concat
    Concat(C, A, B);
    printf("Concat(A,B) = ");
    PrintSString(C);
    printf("\n");

    // Substring
    SubString(Sub, C, 6, 3);
    printf("Substring(C,6,3) = ");
    PrintSString(Sub);
    printf("\n");

    // Compare
    printf("Compare(A,B) = %d\n", StrCompare(A, B));

    return 0;
}
