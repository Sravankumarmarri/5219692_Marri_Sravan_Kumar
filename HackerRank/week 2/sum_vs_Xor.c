long sumXor(long n) {
        if (n == 0) return 1;

    int zeroBits = 0;
    while (n) {
        if ((n & 1) == 0) // check if LSB is zero
            zeroBits++;
        n >>= 1;
    }
    // 2^(number of zero bits)
    return 1L << zeroBits;
}