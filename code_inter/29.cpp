bool g_valid_input = true;
int moreThanHalf(const vector<int>& nums) {
	if (nums.empty()) {
		g_valid_input = false;
		return -1;
	}
	int cur = nums[0];
	int count = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (count == 0) {
			cur = nums[i];
			count = 1;
		}
		else {
			if (cur == nums[i])
				++count;
			else
				--count;
		}
	}
	// check
	count = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (nums[i] == cur)
			++count;
	}
	if (count > (nums.size() >> 1)) {
		g_valid_input = true;
		return cur;
	}
	else {
		g_valid_input = false;
		return -1;
	}

}