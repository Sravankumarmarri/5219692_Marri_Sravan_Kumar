#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for dynamic array
typedef struct {
    int *data;
    int size;
    int capacity;
} DynArray;

// Initialize dynamic array
void initArray(DynArray *arr) {
    arr->capacity = 1;
    arr->size = 0;
    arr->data = (int *)malloc(arr->capacity * sizeof(int));
}

// Append to dynamic array
void appendArray(DynArray *arr, int val) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->data = (int *)realloc(arr->data, arr->capacity * sizeof(int));
    }
    arr->data[arr->size++] = val;
}

// Free dynamic array
void freeArray(DynArray *arr) {
    free(arr->data);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    DynArray *arr = (DynArray *)malloc(n * sizeof(DynArray));
    for (int i = 0; i < n; i++) {
        initArray(&arr[i]);
    }

    int lastAnswer = 0;
    int type, x, y;

    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            // Append y to arr[idx]
            appendArray(&arr[idx], y);
        } else if (type == 2) {
            // Assign lastAnswer to arr[idx][y % size]
            int val = arr[idx].data[y % arr[idx].size];
            lastAnswer = val;
            printf("%d\n", lastAnswer);
        }
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        freeArray(&arr[i]);
    }
    free(arr);

    return 0;
}
