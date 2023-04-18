bool is_prime (int n) {
    if (n == 1)
        return 0;
    for (int a = 2; a * a <= n; a++)
        if (n % a == 0)
            return 0;
    
    return 1;
}
