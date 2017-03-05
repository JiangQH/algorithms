bool isContinuous(vector<int>& nums) {
	if (nums.size() != 5)
		return false;
	// sort it
	sort(nums.begin(), nums.end());
	// get the zero count and gap
	int zero_count = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == 0)
			++zero_count;
	}
	int gap = 0;
	int small = zero_count;
	int big = small + 1;
	while (big < nums.size()) {
		if (nums[big] == nums[small])
			return false;
		gap += nums[big] - nums[small] - 1;
		small = big;
		++big;
	}
	// check
	return zero_count >= gap;
}