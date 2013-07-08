long long pow(long long n, long long k, long long mod) {
	long long r = 1;
	n %= mod;
	while (k > 0) {
		if (k & 1) r = r * n % mod;
		if (k > 1) n = n * n % mod;
		k /= 2;
	}
	return r;
}

long long inverse(long long a, long long mod) {
	long long b = mod, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		swap(a -= t * b, b);
		swap(u -= t * v, v);
	}
	return (u % mod + mod) % mod;
}
