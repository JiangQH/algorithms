int partition(vector<int>& nums, int begin, int end) {
	if (begin >= end)
		return begin;
	int pivot = nums[end];
	int small = begin - 1;
	int walker = begin;
	while (walker < end) {
		if (nums[walker] < pivot) {
			swap(nums[++small], nums[walker]);
		}
		++walker;
	}
	swap(nums[++small], nums[end]);
	return small;
}

void getSmallK(vector<int>& nums, vector<int>& result, int k) {
	if (nums.empty() || k > nums.size() || k < 1)
		return;
	// get partition index
	int begin = 0;
	int end = nums.size() - 1;
	int index = partition(nums, begin, end);
	while (index != k-1) {
		if (index < k-1) {
			begin = index + 1;
			index = partition(nums, begin, end);
		}
		else {
			end = index - 1;
			index = partition(nums, begin, end);
		}
	}
	// found
	for (int i = 0; i < k; ++i) {
		result.push_back(nums[i]);
	}
}


typedef multiset<int, greater<int>> IntSet;
typedef multiset<int, greater<int>>::iterator Iter;
void getSmallK(const vector<int>& data, IntSet& s, int k) {
	if (data.size() < k || k < 1)
		return;
	for (int i = 0; i < data.size(); ++i) {
		if (s.size() < k)
			s.insert(data[k]);
		else
			if (data[k] < s.begin()) {
				s.erase(s.begin());
				s.insert(data[k]);
			}
	}
	
}