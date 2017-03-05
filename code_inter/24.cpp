bool isPostOrder(vector<int>& nums) {
	if (!node)
		return false;
	return isPostOrder(nums, 0, nums.size() - 1);
}

bool isPostOrder(vector<int>& nums, int begin, int end) {
	if (begin > end)
		return false;
	// left
	int smaller = begin;
	while (nums[smaller] < nums[end])
		++smaller;
	// get the split
	int bigger = smaller;
	for (; bigger < end; ++bigger) {
		if (nums[bigger] < nums[end])
			return false;
	}
	// now the left and right
	bool left = true;
	if (smaller > begin) {
		left = isPostOrder(nums, begin, smaller-1);
	}
	bool right = true;
	if (smaller < end) {
		right = isPostOrder(nums, smaller, end-1);
	}
	return left && right;
}