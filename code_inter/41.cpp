vector<int> sum(const vector<int>& nums, int s) {
	vector<int> result;
	if (nums.empty())
		return result;
	int begin = 0;
	int end = nums.size() - 1;
	while (begin < end) {
		if (nums[begin] + nums[end] < s)
			++begin;
		else if (nums[begin] + nums[end] > s)
			--end;
		else {
			result.push_back(nums[begin]);
			result.push_back(nums[end]);
			break;
		}
	}
	return result;
}

void continuousSeq(int s) {
	if (s < 1)
		return;
	int small = 1;
	int big = 2;
	int end = s >> 1 + 2;
	int cur_sum = 3;
	while (big < end && small < big) {
		if (cur_sum > s) {
			++small;
			cur_sum -= small;
		}
		else if (cur_sum < s) {
			++big;
			cur_sum += big;
		}
		else {
			printContinuous(small, big);
			++big;
			cur_sum += big;
		}
	}
}

void printContinuous(int small, int big) {
	for (int i = small; i <= big; ++i)
		cout << i << " ";
	cout << endl;
}