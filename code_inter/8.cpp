int minNum(const vector<int>& nums) {
	if (nums.empty())
		return -1;
	int b_end = 0;
	int s_begin = nums.size() - 1;
	int index = 0;
	while (s_begin > b_end) {
		if (s_begin - b_end == 1) {
			index = s_begin;
			break;
		}
		// check
		int mid = (b_end + s_begin) >> 1;
		if (nums[b_end] == nums[mid] && nums[mid] == nums[s_begin]) {
			return checkInorder(nums, b_end, s_begin);
		}
		else if (nums[b_end] <= nums[mid])
			b_end = mid;
		else if (nums[s_begin] >= nums[mid])
			s_begin = mid;
	}
	return nums[mid];
}

int checkInorder(const vector<int>& nums, int begin, int end) {
	int result = nums[begin];
	for (int i = begin; i <= end; ++i) {
		if (nums[i] < result)
			result = nums[i];
	}
	return result;
}