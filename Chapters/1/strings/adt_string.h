// adt_string.h
#ifndef ADT_STRING_H
#define ADT_STRING_H

typedef struct {
    char *data;   // pointer to dynamically allocated array of characters
    int length;   // length of the string
} String;

// Create an empty string
String CreateEmptyString();

// Return length of string
int StringLength(String S);

// Concatenate S1 and S2 → return new String
String Concatenate(String S1, String S2);

// Utility: Create a String from C-string literal
String CreateFromChars(const char *chars);

// Free memory allocated for a String
void DestroyString(String *S);

#endif
