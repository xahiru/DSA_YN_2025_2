#include "adt2_sstring.h"
#include <string.h>

// Assign from C-string literal
Status StrAssign(SString T, const char *chars) {
    int n = strlen(chars);

    if (n > MAXSTRLEN)
        n = MAXSTRLEN;

    T[0] = n;
    for (int i = 1; i <= n; i++)
        T[i] = chars[i - 1];

    return OK;
}

// Copy S into T
Status StrCopy(SString T, SString S) {
    T[0] = S[0];
    for (int i = 1; i <= S[0]; i++)
        T[i] = S[i];

    return OK;
}

// Clear a string
Status ClearString(SString S) {
    S[0] = 0;
    return OK;
}

// Check if empty
int IsEmpty(SString S) {
    return S[0] == 0;
}

// Return length
int StrLength(SString S) {
    return S[0];
}

// Extract substring
Status SubString(SString Sub, SString S, int pos, int len) {
    // Check bounds
    if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
        return ERROR;

    for (int i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1];

    Sub[0] = len;

    return OK;
}

// Concatenate S1 and S2 into T
Status Concat(SString T, SString S1, SString S2) {
    if (S1[0] + S2[0] <= MAXSTRLEN) {
        // Full concatenation fits
        for (int i = 1; i <= S1[0]; i++)
            T[i] = S1[i];

        for (int i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i];

        T[0] = S1[0] + S2[0];
        return TRUE;
    }
    else if (S1[0] < MAXSTRLEN) {
        // Only part of S2 fits
        for (int i = 1; i <= S1[0]; i++)
            T[i] = S1[i];

        int avail = MAXSTRLEN - S1[0];

        for (int i = 1; i <= avail; i++)
            T[S1[0] + i] = S2[i];

        T[0] = MAXSTRLEN;
        return FALSE;
    }
    else {
        // Only S1 fits, S2 ignored
        for (int i = 0; i <= MAXSTRLEN; i++)
            T[i] = S1[i];

        return FALSE;
    }
}

// Compare lexicographically
int StrCompare(SString S1, SString S2) {
    int len = S1[0] < S2[0] ? S1[0] : S2[0];

    for (int i = 1; i <= len; i++) {
        if (S1[i] != S2[i])
            return S1[i] - S2[i];
    }

    return S1[0] - S2[0];
}
