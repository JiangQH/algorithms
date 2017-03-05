long long fab(int n) {
	if (n < 0)
		return -1;
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	long long fib_2 = 0;
	long long fib_1 = 1;
	long long fib;
	for (int i = 3; i <= n; ++i) {
		fib = fib_2 + fib_1;
		fib_2 = fib_1;
		fib_1 = fib;
	}
	return fib;
}