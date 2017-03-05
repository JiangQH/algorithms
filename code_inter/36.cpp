int reverCount(vector<int>& nums) {
	if (nums.empty())
		return 0;
	vector<int> copy(nums.size());
	return reverCountCore(nums, copy, 0, nums.size()-1);
}

int reverCountCore(vector<int>& nums, vector<int>& copy, int begin, int end) {
	if (begin >= end)
		return 0;
	//middle
	int middle = (end - begin) / 2 + begin;
	int left = reverCountCore(nums, copy, begin, middle);
	int right = reverCountCore(nums, copy, middle+1, end);
	// now do the count job and copy
	int count = 0;
	int real_index = end;
	int left_end = middle;
	int right_end = end;
	while (left_end >= begin && right_end >= middle+1) {
		if (nums[left_end] > nums[right_end]) {
			count += (right_end - middle);
			copy[real_index--] = nums[left_end--];
		}
		else
			copy[real_index--] = nums[right_end--];
	}
	while (left_end >= begin)
		copy[real_index--] = nums[left_end--];
	while (right_end >= middle + 1)
		copy[real_index--] = nums[right_end--];
	// copy back
	for (int i = begin; i <= end; ++i)
		nums[i] = copy[i];
	return count + left + right;
}