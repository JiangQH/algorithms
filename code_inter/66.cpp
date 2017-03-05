bool hasPath(const vector<vector<char>>& matrix, const string& str) {
	if (matrix.empty() || matrix[0].empty() || str.empty())
		return false;
	const int m = matrix.size();
	const int n = matrix[0].size();
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	//check

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (hasPath(matrix, str, visited, i, j, 0))
				return true;
		}
	}
	return false;
}

bool hasPath(const vector<vector<char>>& matrix, const string& str,
			vector<vector<bool>>& visited, int r, int c, int cur_len) {
	if (cur_len == str.size())
		return true;

	bool has = false;
	if (r >= 0 && r < matrix.size() && c >= 0 && c < matrix[0].size() 
		&& !visited[r][c] && matrix[r][c] == str[cur_len]) {
		visited[r][c] = true;
		has = hasPath(matrix, str, visited, r+1, c, cur_len+1) ||
			  hasPath(matrix, str, visited, r-1, c, cur_len+1) ||
			  hasPath(matrix, str, visited, r, c+1, cur_len+1) ||
			  hasPath(matrix, str, visited, r, c-1, cur_len+1);
		if(!has)
			visited[r][c] = false;
	}
	return has;
}