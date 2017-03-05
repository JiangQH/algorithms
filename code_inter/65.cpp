vector<int> maxWindows(const vector<int>& nums, int size) {
	vector<int> result;
	if (nums.size() >= size && size >= 1) {
		//use a deque
		deque<int> window;
		// fill the first window
		for (int i = 0; i < size; ++i) {
			// update the window value
			while (!window.empty() && nums[window.back()] <= nums[i])
				window.pop_back();
			window.push_back(i);
		}
		// now begin move
		for (int i = size; i < nums.size(); ++i) {
			// get the top of the window, fill it in the result
			result.push_back(nums[window.front()]);
			// update the window
			while (!window.empty() && nums[window.back()] <= nums[i])
				window.pop_back();
			while (!window.empty() && i - window.front() >= size)
				window.pop_front();
			window.push_back(i);
		}
		result.push_back(nums[window.front()]);
	}
	return result;
}