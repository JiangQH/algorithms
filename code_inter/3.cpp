bool contains(const vector<vector<int>>& matrix, int num) {
	if (matrix.empty() || matrix[0].empty())
		return false;
	int rows = matrix.size();
	int cols = matrix[0].size();
	int r = 0;
	int c = cols - 1;
	bool found = false;
	while (r < rows && c >= 0) {
		if (matrix[r][c] > num)
			--c;
		else if (matrix[r][c] < num)
			++r;
		else {
			found = true;
			break;
		}
	}
	return found;
}