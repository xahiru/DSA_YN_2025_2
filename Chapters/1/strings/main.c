#include <stdio.h>
#include "adt_string.h"

int main() {
    String S1 = CreateFromChars("Hello");
    String S2 = CreateFromChars(" World");

    printf("S1: %s (len=%d)\n", S1.data, StringLength(S1));
    printf("S2: %s (len=%d)\n", S2.data, StringLength(S2));

    String S3 = Concatenate(S1, S2);
    printf("Concatenated: %s (len=%d)\n", S3.data, StringLength(S3));

    DestroyString(&S1);
    DestroyString(&S2);
    DestroyString(&S3);

    return 0;
}
