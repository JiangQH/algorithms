int lasNum(int n, int m) {
	if (n < 1 || m < 1)
		return -1;
	// get the circle
	vector<int> circle;
	for (int i = 0; i < n; ++i) {
		circle.push_back(i);
	}
	// now del job
	auto cur = circle.begin();
	while (circle.size() > 1) {
		// travel to the m node
		for (int i = 1; i < m; ++i) {
			++cur;
			if (cur == circle.end())
				cur = circle.begin();
		}
		// del this node and move to next
		auto next = cur + 1;
		if (next == circle.end())
			next = circle.begin();
		circle.erase(cur);
		cur = next;
	}
	return *cur;
}