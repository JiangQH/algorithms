void multiply(const vector<int>& a, vector<int>& b) {
	if (a.size() == b.size() && a.size() > 1) {
		b[0] = 1;
		for (int i = 1; i < b.size(); ++i) {
			b[i] = b[i-1] * a[i-1];
		}
		// multiply back
		int temp = 1;
		for (int i = b.size()-1; i >= 0; --i) {
			b[i] *= temp;
			temp *= a[i];
		}
	}
}