int multiple(const vector<int>& nums) {
	if (nums.empty())
		return -1;
	for (int i = 0; i < nums.size(); ++i)
		if (nums[i] < 0 || nums[i] > nums.size()-1)
			return false;

	for (int i = 0; i < nums.size(); ++i) {
		while (i != nums[i]) {
			if (nums[i] == nums[nums[i]])
				return nums[i];
			// swap
			swap(nums[i], nums[nums[i]]);
		}
	}
	return -1;
}