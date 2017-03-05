void printNum(vector<int>& nums) {
	sort(nums.begin(), nums.end(), mycompare);
	for (auto iter : nums)
		cout << *iter;
}

bool mycompare(int a, int b) {
	string num1 = to_string(a);
	string num2 = to_string(b);
	return num1+num2 < num2+num1;
}