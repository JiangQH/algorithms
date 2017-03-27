void bubbleSort(vector<int>& nums) {
  if (nums.empty() || nums.size() == 1)
    return;
  for (int i = nums.size() - 1; i >= 1; --i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] > nums[j+1])
        swap(nums[j], nums[j+1]);
    }
  }

}
