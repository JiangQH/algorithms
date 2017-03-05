int countNum(const vector<int>& nums, int num) {
	if (nums.empty())
		return 0;
	int index1 = firstAppear(nums, num);
	int index2 = lastAppear(nums, num);
	if (index1 != -1 && index2 != -1)
		return index2 - index1 + 1;
	else
		return 0;
}

int firstAppear(const vector<int>& nums, int num) {
	int begin = 0;
	int end = nums.size() - 1;
	while (begin <= end) {
		int middle = (end - begin) / 2 + begin;
		if (nums[middle] > num)
			end = middle - 1;
		else if (nums[middle] < num)
			begin = middle + 1;
		else {
			if (middle == 0 || nums[middle-1] != num)
				return middle;
			else
				end = middle - 1;
		}
	}
	return -1;
}

int lastAppear(const vector<int>& nums, int num) {
	int begin = 0;
	int end = nums.size() - 1;
	while(begin <= end) {
		int middle = (end - begin) / 2 + begin;
		if (nums[middle] > num)
			end = middle - 1;
		else if (nums[middle] < num)
			begin = middle + 1;
		else {
			if (middle == nums.size() - 1 || nums[middle+1] != num)
				return middle;
			else
				begin = middle + 1;
		}
	}
	return -1;
}