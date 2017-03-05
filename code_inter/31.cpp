int maxContinuousSum(const vector<int>& nums) {
	if (nums.empty())
		return 0;
	int max_sum = INT_MIN;
	int cur_sum = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (cur_sum < 0)
			cur_sum = 0;
		cur_sum += nums[i];
		if (cur_sum > max_sum)
			max_sum = cur_sum;
	}
	return max_sum;
}