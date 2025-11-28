// #include <stdio.h>
// #include "adt_string.h"

// int main() {
//     String S = CreateFromChars("ComputerScience");

//     printf("Original: %s\n", S.data);

//     // Substring
//     String sub = Substring(S, 4, 6);
//     printf("Substring(4,6): %s\n", sub.data);

//     // CharAt
//     printf("CharAt(3): %c\n", CharAt(S, 3));

//     // IsEmpty
//     printf("IsEmpty: %d\n", IsEmpty(S));

//     // Compare
//     String A = CreateFromChars("Apple");
//     String B = CreateFromChars("Banana");
//     printf("Compare(Apple, Banana) = %d\n", Compare(A, B));

//     DestroyString(&S);
//     DestroyString(&sub);
//     DestroyString(&A);
//     DestroyString(&B);

//     return 0;
// }




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
