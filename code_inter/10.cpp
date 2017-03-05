int count1(int num) {
	int count = 0;
	while (num) {
		++count;
		num = num & (num-1);
	}
	return count;
}