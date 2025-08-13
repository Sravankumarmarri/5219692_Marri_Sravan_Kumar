#include <stdio.h>
#include <string.h>

long long digSum(const char *n) {
    long long sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum += n[i] - '0';
    }
    return sum;
}

int superDigCalc(long long num) {
    while (num > 9) {
        long long temp = 0;
        while (num > 0) {
            temp += num % 10;
            num /= 10;
        }
        num = temp;
    }
    return (int)num;
}

int main() {
    char n[100001];
    int k;
    scanf("%s %d", n, &k);


    long long sum = digSum(n);


    sum *= k;
    int result = superDigCalc(sum);

    printf("%d\n", result);
    return 0;
}
