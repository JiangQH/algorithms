void reOrder(vector<int>& nums) {
	if (nums.empty())
		return;
	int begin = 0;
	int end = nums.size() - 1;
	while (begin < end) {
		while (end > begin && nums[end] & 1 == 0)
			--end;
		while (begin < end && nums[begin] & 1 == 1)
			++begin;
		if (begin < end) {
			swap(nums[begin], nums[end]);
		}
	}
}