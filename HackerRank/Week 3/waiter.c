#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check prime
int isPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Function to generate first q primes
void generatePrimes(int primes[], int q) {
    int count = 0, num = 2;
    while (count < q) {
        if (isPrime(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

void waiter(int plates[], int n, int q) {
    int primes[q];
    generatePrimes(primes, q);

    int *A = (int*)malloc(n * sizeof(int));
    int topA = n - 1;  // stack A (top is at end)
    for (int i = 0; i < n; i++) A[i] = plates[i];

    int *result = (int*)malloc(n * sizeof(int));
    int resIndex = 0;

    for (int i = 0; i < q; i++) {
        int prime = primes[i];

        int *B = (int*)malloc(n * sizeof(int));
        int topB = -1;
        int *Anew = (int*)malloc(n * sizeof(int));
        int topAnew = -1;

        while (topA >= 0) {
            int plate = A[topA--];  // pop from A
            if (plate % prime == 0)
                B[++topB] = plate;   // push to B
            else
                Anew[++topAnew] = plate; // push to Anew
        }

        // Append B to result (top to bottom)
        while (topB >= 0) {
            result[resIndex++] = B[topB--];
        }

        free(A);
        A = Anew;
        topA = topAnew;
        free(B);
    }

    // Remaining plates in A go to result
    while (topA >= 0) {
        result[resIndex++] = A[topA--];
    }

    // Print result
    for (int i = 0; i < resIndex; i++) {
        printf("%d\n", result[i]);
    }

    free(A);
    free(result);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int plates[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &plates[i]);
    }

    waiter(plates, n, q);

    return 0;
}
