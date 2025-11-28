// adt_string.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adt_string.h"

// Create an empty string
String CreateEmptyString() {
    String S;
    S.length = 0;
    S.data = (char *)malloc(1);
    S.data[0] = '\0';       // empty string
    return S;
}

// Return length of string
int StringLength(String S) {
    return S.length;
}

// Concatenate two strings
String Concatenate(String S1, String S2) {
    String R;
    R.length = S1.length + S2.length;

    R.data = (char *)malloc(R.length + 1); // +1 for '\0'

    memcpy(R.data, S1.data, S1.length);
    memcpy(R.data + S1.length, S2.data, S2.length);

    R.data[R.length] = '\0';
    return R;
}

// Create a String from a C-string
String CreateFromChars(const char *chars) {
    String S;
    S.length = strlen(chars);
    S.data = (char *)malloc(S.length + 1);
    memcpy(S.data, chars, S.length + 1);
    return S;
}

// Free memory allocated for a String
void DestroyString(String *S) {
    if (S->data != NULL) {
        free(S->data);
        S->data = NULL;
    }
    S->length = 0;
}
