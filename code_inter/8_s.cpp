// insert sort
void insertSort(vector<int>& nums) {
	if (nums.empty())
		return;
	for (int i = 1; i < nums.size(); ++i) {
		int val = nums[i];
		int j = i;
		while (j >= 1) {
			if (nums[j] > val)
				nums[j] = nums[j-1];
			else
				break;
			--j;
		}
		nums[j] = val;
	}
}

// buble sort
void bubleSort(vector<int>& nums) {
	if (nums.empty()) {
		return;
	}
	for (int i = nums.size() - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (nums[j] > nums[j+1])
				swap(nums[j], nums[j+1]);
		}
	}
}

// merge sort
void mergeSort(vector<int>& nums) {
	if (nums.empty())
		return;
	vector<int> copy(nums.size());
	mergeSort(nums, copy, 0, nums.size()-1);
}

void mergeSort(vector<int>& data, vector<int>& copy, int begin, int end) {
	if(begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSort(data, copy, begin, mid);
	mergeSort(data, copy, mid+1, end);
	// merge them
	int real_index = end;
	int left_end = mid;
	int right_end = end;
	while (left_end >= begin && right_end > mid) {
		if (data[left_end] > data[right_end])
			copy[real_index--] = data[left_end--];
		else
			copy[real_index--] = data[right_end--];
	}
	while (left_end >= begin)
		copy[real_index--] = data[left_end--];
	while (right_end > mid)
		copy[real_index--] = data[right_end--];
	// copy back
	for (int i = begin; i <= end; ++i)
		data[i] = copy[i];
}


// quick sort
int partition(vector<int>& nums, int begin, int end) {
	if (begin > end)
		return -1;
	int pivot = nums[end];
	int small = begin-1;
	int walker = begin;
	while (walker < end) {
		if (nums[walker] < pivot)
			swap(nums[++small], nums[walker++]);
		else
			++walker;
	}
	swap(nums[++small], nums[end]);
	return small;
}

void quickSort(vector<int>& nums, int begin, int end) {
	if (begin >= end)
		return;
	int index = partition(nums, begin, end);
	if (index > begin)
		quickSort(nums, begin, index-1);
	if (index < end)
		quickSort(nums, index+1, end);
}