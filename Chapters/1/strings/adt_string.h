// adt_string.h
#ifndef ADT_STRING_H
#define ADT_STRING_H

typedef struct {
    char *data;   
    int length;
} String;

// Basic operations
String CreateEmptyString();
int StringLength(String S);
String Concatenate(String S1, String S2);

// New Operations
String Substring(String S, int start, int length);
char CharAt(String S, int position);
int IsEmpty(String S);
int Compare(String S1, String S2);

// Helpers
String CreateFromChars(const char *chars);
void DestroyString(String *S);

#endif
