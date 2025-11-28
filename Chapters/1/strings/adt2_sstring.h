#ifndef ADT2_SSTRING_H
#define ADT2_SSTRING_H

#include <stdio.h>

#define MAXSTRLEN 255        // maximum length of the string
typedef unsigned char Status;

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef unsigned char SString[MAXSTRLEN + 1];
// S[0] = length, S[1..len] = characters

// Basic operations
Status StrAssign(SString T, const char *chars);
Status StrCopy(SString T, SString S);
int StrLength(SString S);
Status ClearString(SString S);
int IsEmpty(SString S);

// New operations (according to ADT)
Status SubString(SString Sub, SString S, int pos, int len);
Status Concat(SString T, SString S1, SString S2);
int StrCompare(SString S1, SString S2);

#endif
