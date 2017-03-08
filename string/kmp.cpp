// the kmp algorithm
vector<int> generateNext(string& str) {
	// generate the next array for kmp algorithm
	vector<int> next(str.size(), 0);
	if (str.empty())
		return next;
	int k = -1;
	int j = 0;
	next[0] = -1;// it is a flag
	while (j < str.size()) {
		// first case
		if (k == -1 || str[j] == str[k]) {
			next[++j] = ++k;
		}
		else {
			// find the next possible k
			k = next[k];
		}
	}
	return next;
}

// optimize the next
vector<int> generateNext(string& str) {
	vector<int> next(str.size(), 0);
	if (str.empty())
		return next;
	int k = -1;
	int j = 0;
	next[0] = -1;
	while (j < str.size()) {
		if (k == -1 || str[j] == str[k]) {
			++j;
			++k;
			if (str[j] == str[k])
				next[j] = next[k];
			else
				next[j] = k;
		}
		else {
			k = next[k];
		}
	}
}

int kmpSubSequence(string& str, string& partern) {
	if (str.empty() || partern.empty())
		return -1;
	vector<int> next = generateNext(partern);
	int i = 0;
	int j = 0;
	while (i < str.size() && j < partern.size()) {
		if (j == -1 || str[i] == str[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j == partern.size())
		return i - partern.size();
	else
		return -1;
}