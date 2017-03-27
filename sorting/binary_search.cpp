int binarySearch(const vector<int>& nums, int val, int begin, int end) {
  if (begin > end)
    return -1;
  int mid = (end - begin) / 2 + begin;
  if (nums[mid] == val)
    return mid;
  else if (nums[mid] > val)
    return binarySearch(nums, val, begin, mid-1);
  else
    return binarySearch(nums, val, mid+1, end);
}
