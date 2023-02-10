vii f;
void factor (int n) {
    int initN = n;
    for (int a = 2; a * a <= initN; a++) {
        if (n % a == 0) {
            int times = 0;
            while (n % a == 0) {
                times++;
                n /= a;
            }

            f.push_back({a, times});
        }
    }

    if (n > 1)
        f.push_back({n, 1});
}
