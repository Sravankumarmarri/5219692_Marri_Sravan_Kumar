#include <stdio.h>
int main() {
    int a, b, sum = 0;
    int c,d;
    printf("Enter two integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sum = a + b + c+ d;
    printf("Sum: %d", sum);

    return 0;
}