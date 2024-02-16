void print(int n) {
    /* If number is smaller than 0, put a - sign
     * and change number to positive */
    if (n < 0) {
        putchar_unlocked('-');
        n *= -1;
    }
 
    /* Remove the last digit and recur */
    if (n/10)
        print(n/10);
 
    /* Print the last digit */
    putchar_unlocked(n % 10 + '0');
}