TP T power(T a, long long k) {
    T r = a;
    for (--k; k > 0; ) {
        if (k & 1) r = r * a;
        if (k > 1) a = a * a;
        k >>= 1;
    }
    return r;
}
