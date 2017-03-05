double probability(int n) {
	if (n < 1)
		return 0;
	// total appear
	const int max_val = 6;
	vector<vector<int>> appear(2, vector<int>(n*max_val+1, 0));
	int cur = 0;
	// the first round
	for (int i = 1; i <= max_val; ++i)
		appear[cur][i] = 1;	
	for (int round = 2; round <= n; ++round) {
		int pre = cur;
		cur = cur - 1;
		// compute
		for (int i = round; i <= round * max_val; ++i) {
			for (int j = i - 1; j >= i-6 && j >= 1; --j) {
				appear[cur][i] += appear[pre][j];
			}
		}
	}
	// get the count
	const int total_count = power(max_val, n);
	for (int i = n; i <= n * max_val; ++i)
		cout << appear[cur][i] * 1.0 / total_count << endl;
}