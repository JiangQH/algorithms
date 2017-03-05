int moveCount(int m, int n, int thresh) {
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	// check
	int count = moveCount(0, 0, thresh, visited);
	return count;
}

int moveCount(int r, int c, int thresh, vector<vector<bool>>& visited) {
	int count = 0;
	if (check(r, c, thresh, visited)) {
		visited[r][c] = true;
		count = 1 + moveCount(r+1, c, thresh, visited) + moveCount(r-1, c, thresh, visited)
					+ moveCount(r, c+1, thresh, visited) + moveCount(r, c-1, thresh, visited);

	}
	return count;
}

bool check(int r, int c, int thresh, const vector<vector<bool>>& visited) {
	if (r < visited.size() && c < visited[0].size() && r >= 0 && c >= 0
		!visited[r][c] && condition(r, c, thresh))
		return true;
	return false;
}

bool condition(int r, int c, int thresh) {
	int result = 0;
	while (r != 0) {
		result += r%10;
		r /= 10;
	}
	while (c != 0) {
		result += c%10;
		c /= 10;
	}
	return result;
}