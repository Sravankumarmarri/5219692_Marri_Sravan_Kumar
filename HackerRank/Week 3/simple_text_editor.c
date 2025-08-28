#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000000

typedef struct {
    int type;      // 1 = append, 2 = delete
    char *data;    // data for undo (deleted/added string)
} Operation;

char S[MAXLEN + 5];     // main string
int len = 0;            // current length of S
Operation stack[MAXLEN]; // stack for undo operations
int top = -1;

void append(char *w) {
    int l = strlen(w);
    strcpy(S + len, w);
    len += l;
    // save undo info
    stack[++top].type = 1;
    stack[top].data = strdup(w);
}

void deleteLast(int k) {
    char *deleted = (char *)malloc(k + 1);
    strncpy(deleted, S + len - k, k);
    deleted[k] = '\0';
    len -= k;
    S[len] = '\0';
    // save undo info
    stack[++top].type = 2;
    stack[top].data = deleted;
}

void printChar(int k) {
    if (k <= len)
        printf("%c\n", S[k - 1]);
}

void undo() {
    if (top < 0) return;
    Operation op = stack[top--];
    if (op.type == 1) { // undo append
        int l = strlen(op.data);
        len -= l;
        S[len] = '\0';
    } else if (op.type == 2) { // undo delete
        int l = strlen(op.data);
        strcpy(S + len, op.data);
        len += l;
    }
    free(op.data);
}

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char w[1000005];
            scanf("%s", w);
            append(w);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            deleteLast(k);
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printChar(k);
        } else if (type == 4) {
            undo();
        }
    }
    return 0;
}
