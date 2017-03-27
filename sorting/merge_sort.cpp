void mergeSort(vector<int>& nums, vector<int>& copy, int begin, int end) {
  if (begin >= end)
    return;
  int mid = (end - begin) / 2 + begin;
  mergeSort(copy, nums, begin, mid);
  mergeSort(copy, nums, mid+1, end);
  // merge them
  merge(copy, nums, begin, end);
}

void merge(vector<int>& nums, vector<int>& copy, int begin, int end) {
  int mid = (end - begin) / 2 + begin;
  int left_walker = begin;
  int right_walker = mid + 1;
  int real_walker = begin;
  while (left_walker <= mid && right_walker <= end) {
    if (nums[left_walker] > nums[right_walker])
      copy[real_walker++] = nums[right_walker++];
    else
      copy[real_walker++] = nums[right_walker++];
  }
  while (left_walker <= mid)
    copy[real_walker++] = nums[left_walker++];
  while (right_walker <= end)
    copy[real_walker++] = nums[right_walker++];
  // shoud copy back? save this step
}

void mergeSort(vector<int>& nums) {
  if (nums.size() <= 1)
    return;
  vector<int> copy = nums;
  mergeSort(nums, copy, 0, nums.size()-1);
}
