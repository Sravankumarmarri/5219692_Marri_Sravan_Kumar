#include <stdio.h>
int main() {
    int a, b, sum = 0;
    int c;
    printf("Enter two integers: ");
    scanf("%d %d %d", &a, &b, &c);
    sum = a + b + c;

    printf("Sum: %d", sum);

    return 0;
}