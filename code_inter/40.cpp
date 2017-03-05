vector<int> appearOnce(vector<int>& nums) {
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
		result ^= nums[i];
	int index = firstRight1(result);
	int result1 = 0;
	int result2 = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (isOneOnindex(nums[i], index))
			result1 ^= nums[i];
		else
			result2 ^= nums[i];
	}
	vector<int> re;
	re.push_back(result1);
	re.push_back(result2);
	return re;
}

int firstRight1(int num) {
	int count = 0;
	while ((num & 0x1 == 0) && (count < 8 * sizeof(int))) {
		++count;
		num >> 1;
	}
	return count;
}

bool isOneOnindex(int num, int index) {
	num = num >> index;
	return num & 0x1;
}