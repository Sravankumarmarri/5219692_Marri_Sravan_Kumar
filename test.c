#include <stdio.h>
int main() {
    int a, b, sum = 0;
    int d;
    printf("Enter two integers: ");
    scanf("%d %d %d", &a, &b, &d);
    sum = a + b + d;

    printf("Sum: %d", sum);

    return 0;
}