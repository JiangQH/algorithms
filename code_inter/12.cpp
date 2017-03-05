void printNum(int n) {
	if (n < 1)
		return;
	vector<int> dict(n);
	printCore(dict, 0);
}

void printCore(vector<int>& nums, int pos) {
	if (pos == nums.size()) {
		printNum(nums);
		return;
	}
	for (int i = 0; i <= 9; ++i) {
		nums[pos] = i;
		printCore(nums, pos+1);
	}
}

void printNum(vector<int>& nums) {
	bool begin_zero = true;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] != 0) {
			cout << nums[i];
			begin_zero = false;
		}
		else if (!begin_zero) {
			cout << nums[i];
		}
	}
}