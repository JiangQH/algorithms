int countNum(int n, int x) {
	if (n < 0)
		return 0;
	int a, b, tmp;
	int high = n;
	int i = 1;
	int total = 0;
	while (high != 0) {
		high = n / power(10, i);// high
		tmp = n % power(10, i);
		curr = tmp / power(10, i-1);
		low = tmp % power(10, i-1);
		if (curr == x)
			total += high * power(10, i-1) + low + 1;
		else if curr > x
			total += (high+1) * power(10, i-1);
		else
			total += high * power(10, i-1)
	}
	return total;
}