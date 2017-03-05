void printString(string& s) {
	if (s.empty())
		return;
	for (int i = 1; i <= s.size(); ++i) {
		vector<char> stores;
		printCore(s, 0, i, stores);
	}
}

void printCore(string& s, int begin, int m, vector<char> stores) {
	if (m == 0) {
		for (auto ch: stores)
			cout << ch;
		cout << " ";
		return;
	}
	if (s.size() - begin < m) {
		return;
	}
	// two case
	stores.push_back(s[begin]);
	printCore(s, begin+1, m-1, stores);
	stores.pop_back();
	printCore(s, begin+1, m, stores);
}