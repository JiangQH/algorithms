char firstAppear(const string& str) {
	vector<int> dict(256, 0);
	for (auto ch : str)
		++dict[ch];
	for (auto ch : str)
		if (dict[ch] == 1)
			return ch;
	return '\0';
}