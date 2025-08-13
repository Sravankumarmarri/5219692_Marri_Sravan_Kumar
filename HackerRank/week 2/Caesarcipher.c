#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarCipher(char s[], int k) {
    k = k % 26;
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (isalpha(ch)) {
            if (isupper(ch)) {
                s[i] = ((ch - 'A' + k) % 26) + 'A';
            } else {
                s[i] = ((ch - 'a' + k) % 26) + 'a';
            }
        }
    }
}

int main() {
    int n, k;
    char s[1000];

    scanf("%d", &n);   
    scanf("%s", s);    
    scanf("%d", &k); 

    caesarCipher(s, k);

    printf("%s\n", s);

    return 0;
}
