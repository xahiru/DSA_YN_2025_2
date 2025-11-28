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
    S.data[0] = '\0';
    return S;
}

// Get string length
int StringLength(String S) {
    return S.length;
}

// Concatenate two strings
String Concatenate(String S1, String S2) {
    String R;
    R.length = S1.length + S2.length;
    R.data = (char *)malloc(R.length + 1);

    memcpy(R.data, S1.data, S1.length);
    memcpy(R.data + S1.length, S2.data, S2.length);
    R.data[R.length] = '\0';

    return R;
}

// Substring: start is 1-based index
String Substring(String S, int start, int length) {
    if (start < 1 || start > S.length || length < 0)
        return CreateEmptyString();

    int maxLen = S.length - (start - 1);
    if (length > maxLen)
        length = maxLen;

    String R;
    R.length = length;
    R.data = (char *)malloc(length + 1);

    memcpy(R.data, S.data + (start - 1), length);
    R.data[length] = '\0';

    return R;
}

// CharAt: 1-based index
char CharAt(String S, int position) {
    if (position < 1 || position > S.length)
        return '\0';
    return S.data[position - 1];
}

// Check if string is empty
int IsEmpty(String S) {
    return S.length == 0;
}

// Compare lexicographically
int Compare(String S1, String S2) {
    return strcmp(S1.data, S2.data);
}

// Create from C-string
String CreateFromChars(const char *chars) {
    String S;
    S.length = strlen(chars);
    S.data = (char *)malloc(S.length + 1);
    memcpy(S.data, chars, S.length + 1);
    return S;
}

// Free allocated memory
void DestroyString(String *S) {
    if (S->data) {
        free(S->data);
        S->data = NULL;
    }
    S->length = 0;
}
