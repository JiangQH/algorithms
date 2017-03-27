int partition(vector<int>& nums, int begin, int end) {
  if (begin > end)
    return -1;
  if (begin == end)
    return begin;
  int pivot = nums[end];
  int small = begin-1;
  for (int i = begin; i < end; ++i) {
    if (nums[i] < pivot)
      swap(nums[++small], nums[i]);
  }
  swap(nums[++small], nums[end]);
  return small;
}

int partition2(vector<int>& nums, int begin, int end) {
  if (begin > end)
    return -1;
  if (begin == end)
    return begin;
  int pivot_loca = end;
  int pivot = nums[end];
  --end;
  while (begin <= end) {
    while (nums[begin] < pivot)
      ++begin;
    while (nums[end] >= pivot)
      --end;
    if (begin <= end) {
      swap(nums[begin++], nums[end--]);
    }
  }
  swap(nums[begin], nums[pivot_loca]);
  return begin;
}
