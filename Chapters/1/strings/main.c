#include <stdio.h>
#include "adt_string.h"

int main() {
    String S = CreateFromChars("ComputerScience");

    printf("Original: %s\n", S.data);

    // Substring
    String sub = Substring(S, 4, 6);
    printf("Substring(4,6): %s\n", sub.data);

    // CharAt
    printf("CharAt(3): %c\n", CharAt(S, 3));

    // IsEmpty
    printf("IsEmpty: %d\n", IsEmpty(S));

    // Compare
    String A = CreateFromChars("Apple");
    String B = CreateFromChars("Banana");
    printf("Compare(Apple, Banana) = %d\n", Compare(A, B));

    DestroyString(&S);
    DestroyString(&sub);
    DestroyString(&A);
    DestroyString(&B);

    return 0;
}
