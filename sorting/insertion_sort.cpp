void insertionSort(vector<int>& nums) {
  if (nums.empty() || nums.size() == 1)
    return;
  for (int i = 1; i < nums.size(); ++i) {
    int val = nums[i];
    int j = i - 1;
    while (j >= 0 && nums[j] > val) {
      nums[j+1] = nums[j];
      --j;
    }
    nums[j+1] = val;
  }
}
