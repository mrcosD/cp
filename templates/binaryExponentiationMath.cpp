int pow(int a, int b, int M) {
    if (b == 0) {
        return 1 % M;
    }
    if (b % 2 == 1) {
        return pow(a, b - 1, M) * a % M;
    } else {
        int ak = pow(a, b / 2, M);
        return ak * ak % M;
    }
}
