int add2Num(int a, int b) {
	do {
		int sum = a^b;
		int carry = (a&b) << 1;
		a = carry;
		b = sum;
	}while (a);
	return b;
}