char* counterGame(long n) {
    static char win[10]; 
    int m = 0;

    while (n != 1) {
        
        if ((n & (n - 1)) == 0) {
            n >>= 1; // divide by 2
        } else {
        
            long p = 1L << ((int)log2(n));
            n -= p;
        }
        m++;
    }

    if (m % 2 == 1)
        strcpy(win, "Louise");
    else
        strcpy(win, "Richard");

    return win;
}
