class CharStatics{
public:
	CharStatics():index(0) {
		for (int i = 0; i < 256; ++i)
			dict.push_back(-1);
	}
	void insert(char) {
		if (dict[char] == -1)
			dict[char] = index;
		else
			dict[char] = -2;
	}
	char firstAppear() {
		char ch = '\0';
		int min_index = INT_MAX;
		for (int i = 0; i < dict.size(); ++i) {
			if (dict[i] >= 0 && dict[i] < min_index) {
				ch = char(i);
				min_index = dict[i];
			}
		}
		return ch;
	}
private:
	vector<int> dict;
	int index;
};