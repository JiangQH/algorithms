long uglyNum(int n) {
	vector<long> ugly(n);
	ugly[0] = 1;
	auto mult2 = ugly.begin();
	auto mult3 = ugly.begin();
	auto mult5 = ugly.begin();
	int index = 1;
	while (index < n) {
		// get next ugly num
		long num = min3(2*(*mult2), 3*(*mult3), 5*(*mult5));
		ugly[index] = num;
		while (2 * (*mult2) < num)
			++mult2;
		while (3 * (*mult3) < num)
			++mult3;
		while (5 * (*mult5) < num)
			++mult5;
	}
	return ugly[n-1];
}

long min3(long a, long b, long c) {
	return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}